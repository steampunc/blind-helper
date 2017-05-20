#include "third_party/proto/stack_proto.h"
#include <iostream>

namespace muan {
namespace proto {

void* ProtoFailOnBlockAlloc(size_t) {
  // Fail loudly here - this should be caught quickly when it
  // happens! If this gets called, it means that a proto was too large for the
  // buffer that we provided it.
  std::cout << "Buffer not big enough for proto!" << std::endl;
}

void ProtoFailOnBlockFree(void*, size_t) {
  // This should _really_ never happen - if it does, it means that the
  // BlockAlloc above didn't fail. Be extra loud here - probably just crash the
  // whole program if this ever gets called, with a nice loud neon sign pointing
  // to this file.
  std::cout << "Oh dear...something has gone horribly wrong in " << std::endl;
}

}  // namespace proto
}  // namespace muan
