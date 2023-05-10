#include <iostream>

class Dialog
{
public:
	void close() { std::cout << "Dialog close" << std::endl; }
};
class Button
{
	Dialog* dlg;
public:
	void set_dialog(Dialog* p) { dlg = p; }
	void click() { dlg->close(); }
};
int main()
{
	Dialog dlg;
	Button btn;
	btn.set_dialog(&dlg);
	btn.click();
}
