This is the repository for a work-in-progress application that takes a camera/webcam input and transforms it to stereo sound.

## Current dependencies
* `third_party`
  * protobuf
    This is google's data sharing framework. It's really cool, and I had experience using it on my robotics team, so it's getting used here too. The alternative to protobuf messages are simply structs.
  * proto
    Going along with protobuf is some code from [Citrus Circuits](https://github.com/frc1678) which implements a stack-allocated arena for protobuf messages.
  * queues
    More code copied from [Citrus Circuits](https://github.com/frc1678) which is used to send messages between threads within the code. The `queue_manager` uses these queues, which fill up with protobuf messages, then hands instances of them out to whatever bit of code requests them.
  * optional
    The optional library allows messages sent to be _optional_, so if there hasn't been anything written to the queues yet then it doesn't exist or try and perform computations on null values.

  * OpenCV 2
    [OpenCV](https://github.com/opencv/opencv) is one of the most well-known vision libraries, for both C++ and Python. I'm using it for the camera and image manipulation

  * PortAudio
    [PortAudio](http://www.portaudio.com/) is a cross-platform audio library. It allows me to generate my own sound waves, superimposed upon eachother. This library offers a _lot_ more fine control over audio and is a must-use if you want to write code involving audio generation.


