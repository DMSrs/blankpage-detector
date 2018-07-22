#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/features2d.hpp>

#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>

#define DEBUG false

using namespace cv;
using namespace std;

void usage(int argc, char* argv[]){
  cout << "Usage: " << argv[0] << " [image-list]" << endl;
  cout << "Output: A list of images (one per line) that aren't white" << endl;
}

bool is_whitepage(char* filename){
  Mat im = imread(filename);

  std::vector<KeyPoint> keypoints;

  SimpleBlobDetector::Params params;
  params.minThreshold = 10;
  params.maxThreshold = 200;
  params.filterByArea = true;
  params.minArea = 20;
  params.filterByCircularity = false;;
  params.minCircularity = 0;
  params.filterByConvexity = false;
  params.minConvexity = 0;
  params.filterByInertia = true;
  params.minInertiaRatio = 0.01;
 
  #if CV_MAJOR_VERSION < 3   // If you are using OpenCV 2
    SimpleBlobDetector detector(params);
    detector.detect( im, keypoints);
  #else
    Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);
    detector->detect( im, keypoints);
  #endif

  double blobs_ratio = (double) keypoints.size() / (1.0 * im.rows*im.cols);

  if(DEBUG){
    cout << "Blobs Ratio: " << blobs_ratio << endl;
    cout << "We've detected " << keypoints.size() << " keypoints" << endl;
  }

  bool is_whitepage = false;

  if (blobs_ratio < 1E-6) {
    is_whitepage = true;
    if(DEBUG)
      cout << "White page!" << endl;
  }

  return is_whitepage;
}


int main(int argc, char* argv[]){
  Mat image;
  if(argc < 2){
    cerr << "Invalid input" << endl;
    usage(argc, argv);
    return 1;
  }

  for (int i=1; i<argc; i++){
    if(!is_whitepage(argv[i])){
      cout << argv[i] << endl;
    }
  }

  image = imread(argv[1], CV_LOAD_IMAGE_COLOR);

  if(!image.data){
    cerr << "No image data." << endl;
    return 1;
  }
}
