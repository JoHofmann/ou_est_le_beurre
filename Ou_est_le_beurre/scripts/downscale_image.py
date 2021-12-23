import cv2 as cv
import sys
import numpy as np
from os import listdir
from os.path import isfile, join

# constants
PX_SIZE = 18
OFFSET_LEFT = -6 + (PX_SIZE // 2)
OFFSET_TOP = -9 + (PX_SIZE // 2)
IMG_PATHS = "../resources/textures/muttern/"

onlyfiles = [f for f in listdir(IMG_PATHS) if isfile(join(IMG_PATHS, f))]

for filename in onlyfiles:
    img_downsampled = np.zeros((32, 32, 4), np.uint8)
    img = cv.imread(IMG_PATHS + filename, cv.IMREAD_UNCHANGED)
    if img is None:
        sys.exit("Could not read the image.")

    row = OFFSET_TOP
    i = 0
    while row < img.shape[0]:
        if(i == 16 or i == 20):
            row -= 7
        col = OFFSET_LEFT
        j = 0
        while col < img.shape[1]:
            (b, g, r, a) = img[row, col]
            color = (int(b), int(g), int(r), int(a))
            cv.rectangle(img_downsampled, (j, i), (j, i), color=color, thickness=1)

            col += PX_SIZE
            j += 1
        row += PX_SIZE
        i += 1

    cv.imwrite(filename, img_downsampled)



# pixelsize ~17px
# offset left 2px / right 2-3px