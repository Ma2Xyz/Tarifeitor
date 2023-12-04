#include <iostream>
#include "../headers/app.h"
#include "../headers/mainFrame.h"
#include <wx/wx.h>
using namespace std;

wxIMPLEMENT_APP(app);

bool app::OnInit() {
    mainFrame* mainFrameVar = new mainFrame("Tarifeitor");
    mainFrameVar->SetClientSize(370, 170);
    mainFrameVar->Center();
    mainFrameVar->Show();
    return true;
}