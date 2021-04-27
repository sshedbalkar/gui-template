#include "Application.h"

#include "Frame.h"

bool Application::OnInit() {
  Frame *frame = new Frame("Hello World", wxPoint(50, 50), wxSize(450, 340));
  frame->Show(true);
  return true;
}
