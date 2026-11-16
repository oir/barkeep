#include <barkeep/barkeep.h>

// Compile-only examples of downstream subclasses. Keep these types explicit so
// changes to the extension interface fail the C++ builds.
class CustomDisplay : public barkeep::BaseDisplay {
 protected:
  long render_(bool, const std::string&) override { return render_message_(); }
};

class CustomAnimation : public barkeep::AnimationDisplay {
 public:
  unsigned short& current_frame() { return frame_; }
};

class CustomDisplayer : public barkeep::AsyncDisplayer {
 public:
  long& last_newline_count() { return last_num_newlines_; }
};
