add_library(camera_Camera
  Camera.hpp
  Camera.cpp)
target_link_libraries(camera_Camera
  ${OpenCV_LIBS})
