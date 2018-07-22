# Blank Page Detector
Detects if the provided image contains any feature (like text or
drawings). If there are "enough features for it to be considered non-blank", 
its path will be returned.

## Requirements
- OpenCV
- Clang

## Usage
```
$ ./bpd.out test-image/*.jpg
test-image/5.jpg
test-image/6.jpg
```
