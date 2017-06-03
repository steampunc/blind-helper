# Listenr (tentative name)

This is the repository for a work-in-progress application that takes a camera/webcam input and transforms it to stereo sound.

##$ Current dependencies
* `third_party`
  * protobuf
    This is google's data sharing framework. It's really cool, and I had experience using it on my robotics team, so it's getting used here too. The alternative to protobuf messages are simply structs.
  * proto
    Going along with protobuf is some code from [Citrus Circuits](https://github.com/frc1678) which implements a stack-allocated arena for protobuf messages.
  * queues
    More code copied from [Citrus Circuits](https://github.com/frc1678) which is used to send messages between threads within the code. The `queue_manager` uses these queues, which fill up with protobuf messages, then hands instances of them out to whatever bit of code requests them.
  * optional
    The optional library allows messages sent to be _optional_, so if there hasn't been anything written to the queues yet then it doesn't exist or try and perform computations on null values.


