#include "MyForm.h"
#include "MenuForm.h"
#include "Nivel2.h" // <--- Agregar esto

using namespace System;
using namespace System::Windows::Forms;

void main()
{
    // Application::Run(gcnew TFAlgoritmos::MenuForm()); 
    Application::Run(gcnew TFAlgoritmos::Nivel2()); // <--- Cambiar aquí para probar
}