add_library(engine_MarkerDetector
  MarkerDetector.hpp
  MarkerDetector.cpp)
target_link_libraries(engine_MarkerDetector
  ${OpenCV_LIBS})
