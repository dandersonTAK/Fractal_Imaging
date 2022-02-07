# CMakeList.txt : CMake project for Fractal_Project_v2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Fractal_Project_v2     "Fractal_Generator.cpp" "BitmapFileHeader.h" "BitmapInfoHeader.h" "Bitmap.cpp" "Bitmap.h" "Mandelbrot.cpp" "Mandelbrot.h" "Zoom.h" "ZoomList.cpp" "FractalCreator.h" "FractalCreator.cpp" "RGB.h" "RGB.cpp" )

# TODO: Add tests and install targets if needed.
