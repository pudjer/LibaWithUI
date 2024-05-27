#include <iostream>
#include "GetDb.h"
#include "BookRepository.h"
#include "ClientRepository.h"
#include "MyForm.h"

using namespace LibaWithUI;
using namespace System;
using namespace System::Windows::Forms;
using namespace std;
using namespace Repositories;

[STAThreadAttribute]
int main() {
    //Запускаем окно
    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();
    MyForm form;
    Application::Run(% form);
    return 0;

}
