add_executable(camera_stream
  cameraStream.cpp)

target_link_libraries(camera_stream
  engine_MarkerDetector
  camera_Camera)
