#pragma once
#include "Controladora.h"

namespace TFAlgoritmos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			juego = gcnew Controladora();

			
			try {
				panelDialogo->BackgroundImage = System::Drawing::Image::FromFile("imagenes/supervisor.png");
			}
			catch (...) {}

			panelDialogo->Visible = false;
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Controladora^ juego;
		bool w, s, a, d;
		int idActualInteraccion;

	private: System::Windows::Forms::Panel^ panelDialogo;
	private: System::Windows::Forms::Button^ btnCuestionar;
	private: System::Windows::Forms::Button^ btnObedecer;
	private: System::Windows::Forms::Label^ lblOrden;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->panelDialogo = (gcnew System::Windows::Forms::Panel());
			   this->btnCuestionar = (gcnew System::Windows::Forms::Button());
			   this->btnObedecer = (gcnew System::Windows::Forms::Button());
			   this->lblOrden = (gcnew System::Windows::Forms::Label());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->panelDialogo->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // panelDialogo
			   // 
			   this->panelDialogo->BackColor = System::Drawing::Color::Transparent;
			   this->panelDialogo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->panelDialogo->Controls->Add(this->btnCuestionar);
			   this->panelDialogo->Controls->Add(this->btnObedecer);
			   this->panelDialogo->Controls->Add(this->lblOrden);
			   this->panelDialogo->Location = System::Drawing::Point(50, 500);
			   this->panelDialogo->Name = L"panelDialogo";
			   this->panelDialogo->Size = System::Drawing::Size(700, 220);
			   this->panelDialogo->TabIndex = 0;
			   this->panelDialogo->Visible = false;
			   // 
			   // btnCuestionar
			   // 
			   this->btnCuestionar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				   static_cast<System::Int32>(static_cast<System::Byte>(20)));
			   this->btnCuestionar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnCuestionar->ForeColor = System::Drawing::Color::Red;
			   this->btnCuestionar->Location = System::Drawing::Point(170, 150);
			   this->btnCuestionar->Name = L"btnCuestionar";
			   this->btnCuestionar->Size = System::Drawing::Size(120, 40);
			   this->btnCuestionar->TabIndex = 2;
			   this->btnCuestionar->Text = L"Cuestionar";
			   this->btnCuestionar->UseVisualStyleBackColor = false;
			   this->btnCuestionar->Click += gcnew System::EventHandler(this, &MyForm::btnCuestionar_Click);
			   // 
			   // btnObedecer
			   // 
			   this->btnObedecer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				   static_cast<System::Int32>(static_cast<System::Byte>(20)));
			   this->btnObedecer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnObedecer->ForeColor = System::Drawing::Color::White;
			   this->btnObedecer->Location = System::Drawing::Point(30, 150);
			   this->btnObedecer->Name = L"btnObedecer";
			   this->btnObedecer->Size = System::Drawing::Size(120, 40);
			   this->btnObedecer->TabIndex = 1;
			   this->btnObedecer->Text = L"Obedecer";
			   this->btnObedecer->UseVisualStyleBackColor = false;
			   this->btnObedecer->Click += gcnew System::EventHandler(this, &MyForm::btnObedecer_Click);
			   // 
			   // lblOrden
			   // 
			   this->lblOrden->BackColor = System::Drawing::Color::Transparent;
			   this->lblOrden->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblOrden->ForeColor = System::Drawing::Color::LightGreen;
			   this->lblOrden->Location = System::Drawing::Point(30, 30);
			   this->lblOrden->Name = L"lblOrden";
			   this->lblOrden->Size = System::Drawing::Size(430, 100);
			   this->lblOrden->TabIndex = 0;
			   this->lblOrden->Text = L"Texto de orden...";
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Interval = 30;
			   this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(800, 800);
			   this->Controls->Add(this->panelDialogo);
			   this->DoubleBuffered = true;
			   this->Name = L"MyForm";
			   this->Text = L"Acto I: Neo-Algoritmo";
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			   this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			   this->panelDialogo->ResumeLayout(false);
			   this->ResumeLayout(false);

		   }
#pragma endregion

		   
		   // LÓGICA DEL JUEGO
		   
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);

		if (panelDialogo->Visible == false) {
			juego->MoverTodo(w, s, a, d);

			int id = juego->VerificarColisionNivel1();
			if (id > 0) {
				idActualInteraccion = id;
				MostrarDialogoTerminal(id);
			}

			static bool yaHablo = false;
			if (juego->VerificarColisionSupervisor()) {
				if (!yaHablo) {
					if (juego->GetVoluntadKael() < 5) MostrarDialogoSupervisor(false);
					else MostrarDialogoSupervisor(true);
					yaHablo = true;
				}
			}
			else {
				yaHablo = false;
			}
		}

		juego->DibujarTodo(buffer->Graphics);
		buffer->Render(g);
		delete buffer; delete espacio; delete g;
	}

		   
		   // DIALOGOS DE TERMINALES 
		   
		   void MostrarDialogoTerminal(int id) {
			  
			   try {
				   panelDialogo->BackgroundImage = System::Drawing::Image::FromFile("imagenes/supervisor_2.png");
			   }
			   catch (...) {}

			  
			   panelDialogo->Size = System::Drawing::Size(700, 220);
			   int x = (this->ClientSize.Width - 700) / 2;
			   panelDialogo->Location = System::Drawing::Point(x, 550);

			   
			   lblOrden->Location = System::Drawing::Point(25, 25);
			   lblOrden->Size = System::Drawing::Size(450, 95); 
			   lblOrden->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold));

			   btnObedecer->Location = System::Drawing::Point(25, 130);
			   btnCuestionar->Location = System::Drawing::Point(160, 130);

			   panelDialogo->Visible = true;
			   panelDialogo->BringToFront();
			   w = s = a = d = false;

			   btnCuestionar->Visible = true;
			   btnObedecer->Visible = true;
			   btnObedecer->Text = "Obedecer";

			   switch (id) {
			   case 1: lblOrden->Text = "ORDEN: Proceda a la Rejilla Gamma-7 para el reinicio de protocolos."; break;
			   case 2: lblOrden->Text = "ORDEN: La emoción es una variable de error. Elimínela inmediatamente."; break;
			   case 3: lblOrden->Text = "ORDEN: Tome el sector 3B. Es 0.003% más rápido que la ruta estándar."; break;
			   case 4: lblOrden->Text = "ORDEN: Su tiempo libre ha sido reasignado a la vigilancia."; break;
			   case 5: lblOrden->Text = "ORDEN: Desactive la memoria de la Unidad 59. Es defectuosa."; break;
			   }
		   }

		  
		   void MostrarDialogoSupervisor(bool esElFinal) {
			  
			   try {
				   panelDialogo->BackgroundImage = System::Drawing::Image::FromFile("imagenes/supervisor.png");
			   }
			   catch (...) {}

			  
			   panelDialogo->Location = System::Drawing::Point(0, 0);
			   panelDialogo->Size = this->ClientSize;

			  
			   lblOrden->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold));

			  
			   lblOrden->Location = System::Drawing::Point(20, 20);

			   
			   lblOrden->Size = System::Drawing::Size(420, 240);

			  
			   lblOrden->TextAlign = System::Drawing::ContentAlignment::TopLeft;

			   
			   btnObedecer->Location = System::Drawing::Point(50, 320); 

			   panelDialogo->Visible = true;
			   panelDialogo->BringToFront();
			   w = s = a = d = false;

			   btnCuestionar->Visible = false;
			   btnObedecer->Visible = true;
			   btnObedecer->Text = "Continuar";

			   if (!esElFinal) {
				   // DIÁLOGO NORMAL (VERDE)
				   lblOrden->ForeColor = System::Drawing::Color::LightGreen; 
				   lblOrden->Text = "SUPERVISOR:\n\nUnidad Kael 5-9.\n\nSu eficiencia ha disminuido.\nComplete las 5 tareas de mantenimiento en las terminales inmediatamente o será reiniciado.";
				   idActualInteraccion = 0;
			   }
			   else {
				   // DIÁLOGO DE ERROR (ROJO)
				   lblOrden->ForeColor = System::Drawing::Color::Red; 
				   lblOrden->Text = "SUPERVISOR:\n\n¡ERROR CRÍTICO DETECTADO!\n\nUnidad Kael, sus niveles de Voluntad exceden los parámetros permitidos.\n\n¡Su conciencia es un riesgo para el sistema!";
				   idActualInteraccion = 999;
			   }
		   }

	private: System::Void btnCuestionar_Click(System::Object^ sender, System::EventArgs^ e) {
		juego->ResolverInteraccion(idActualInteraccion);
		panelDialogo->Visible = false;
		this->Focus();
	}

	private: System::Void btnObedecer_Click(System::Object^ sender, System::EventArgs^ e) {
		if (idActualInteraccion == 999) {
			timer1->Enabled = false;
			MessageBox::Show("ACTO I COMPLETADO\nKael escapa del laboratorio.");
			this->Close();
			return;
		}
		panelDialogo->Visible = false;
		this->Focus();
	}

	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::W) w = true;
		if (e->KeyCode == Keys::S) s = true;
		if (e->KeyCode == Keys::A) a = true;
		if (e->KeyCode == Keys::D) d = true;
	}

	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::W) w = false;
		if (e->KeyCode == Keys::S) s = false;
		if (e->KeyCode == Keys::A) a = false;
		if (e->KeyCode == Keys::D) d = false;
	}
	};
}