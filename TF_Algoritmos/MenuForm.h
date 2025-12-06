#pragma once
#include "MyForm.h" 

namespace TFAlgoritmos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MenuForm : public System::Windows::Forms::Form
	{
	public:
		MenuForm(void)
		{
			InitializeComponent();

			// Carga segura del fondo
			try {
				this->BackgroundImage = System::Drawing::Image::FromFile("imagenes/fondo_menu.png");
			}
			catch (...) {}
		}

	protected:
		~MenuForm()
		{
			if (components) delete components;
		}

	private:
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Button^ btnJugar;
		System::Windows::Forms::Button^ btnInstrucciones;
		System::Windows::Forms::Button^ btnCreditos;
		System::Windows::Forms::Button^ btnSalir;

		// Panel para pedir nombre
		System::Windows::Forms::Panel^ panelNombre;
		System::Windows::Forms::TextBox^ txtNombre;
		System::Windows::Forms::Button^ btnGo;
		System::Windows::Forms::Label^ lblPedirNombre;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->btnJugar = (gcnew System::Windows::Forms::Button());
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->panelNombre = (gcnew System::Windows::Forms::Panel());
			this->btnGo = (gcnew System::Windows::Forms::Button());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->lblPedirNombre = (gcnew System::Windows::Forms::Label());
			this->panelNombre->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->BackColor = System::Drawing::Color::Transparent;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Consolas", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitulo->ForeColor = System::Drawing::Color::White;
			this->lblTitulo->Location = System::Drawing::Point(90, 95);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(648, 56);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"EL CÓDIGO DEL EQUILIBRIO";
			this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnJugar
			// 
			this->btnJugar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->btnJugar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnJugar->Font = (gcnew System::Drawing::Font(L"Consolas", 16, System::Drawing::FontStyle::Bold));
			this->btnJugar->ForeColor = System::Drawing::Color::Lime;
			this->btnJugar->Location = System::Drawing::Point(300, 300);
			this->btnJugar->Name = L"btnJugar";
			this->btnJugar->Size = System::Drawing::Size(200, 50);
			this->btnJugar->TabIndex = 1;
			this->btnJugar->Text = L"NUEVA PARTIDA";
			this->btnJugar->UseVisualStyleBackColor = false;
			this->btnJugar->Click += gcnew System::EventHandler(this, &MenuForm::btnJugar_Click);
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->btnInstrucciones->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnInstrucciones->Font = (gcnew System::Drawing::Font(L"Consolas", 16, System::Drawing::FontStyle::Bold));
			this->btnInstrucciones->ForeColor = System::Drawing::Color::White;
			this->btnInstrucciones->Location = System::Drawing::Point(300, 370);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(200, 50);
			this->btnInstrucciones->TabIndex = 2;
			this->btnInstrucciones->Text = L"INSTRUCCIONES";
			this->btnInstrucciones->UseVisualStyleBackColor = false;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &MenuForm::btnInstrucciones_Click);
			// 
			// btnCreditos
			// 
			this->btnCreditos->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->btnCreditos->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCreditos->Font = (gcnew System::Drawing::Font(L"Consolas", 16, System::Drawing::FontStyle::Bold));
			this->btnCreditos->ForeColor = System::Drawing::Color::White;
			this->btnCreditos->Location = System::Drawing::Point(300, 440);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(200, 50);
			this->btnCreditos->TabIndex = 3;
			this->btnCreditos->Text = L"CRÉDITOS";
			this->btnCreditos->UseVisualStyleBackColor = false;
			this->btnCreditos->Click += gcnew System::EventHandler(this, &MenuForm::btnCreditos_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->btnSalir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Consolas", 16, System::Drawing::FontStyle::Bold));
			this->btnSalir->ForeColor = System::Drawing::Color::Red;
			this->btnSalir->Location = System::Drawing::Point(300, 510);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(200, 50);
			this->btnSalir->TabIndex = 4;
			this->btnSalir->Text = L"SALIR";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &MenuForm::btnSalir_Click);
			// 
			// panelNombre
			// 
			this->panelNombre->BackColor = System::Drawing::Color::Black;
			this->panelNombre->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelNombre->Controls->Add(this->btnGo);
			this->panelNombre->Controls->Add(this->txtNombre);
			this->panelNombre->Controls->Add(this->lblPedirNombre);
			this->panelNombre->Location = System::Drawing::Point(200, 250);
			this->panelNombre->Name = L"panelNombre";
			this->panelNombre->Size = System::Drawing::Size(400, 200);
			this->panelNombre->TabIndex = 5;
			this->panelNombre->Visible = false;
			// 
			// btnGo
			// 
			this->btnGo->BackColor = System::Drawing::Color::Green;
			this->btnGo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnGo->ForeColor = System::Drawing::Color::White;
			this->btnGo->Location = System::Drawing::Point(150, 130);
			this->btnGo->Name = L"btnGo";
			this->btnGo->Size = System::Drawing::Size(100, 40);
			this->btnGo->TabIndex = 0;
			this->btnGo->Text = L"INICIAR";
			this->btnGo->UseVisualStyleBackColor = false;
			this->btnGo->Click += gcnew System::EventHandler(this, &MenuForm::btnGo_Click);
			// 
			// txtNombre
			// 
			this->txtNombre->Font = (gcnew System::Drawing::Font(L"MS Gothic", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtNombre->ForeColor = System::Drawing::SystemColors::Window;
			this->txtNombre->Location = System::Drawing::Point(50, 80);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(300, 26);
			this->txtNombre->TabIndex = 1;
			// 
			// lblPedirNombre
			// 
			this->lblPedirNombre->AutoSize = true;
			this->lblPedirNombre->Font = (gcnew System::Drawing::Font(L"MS PGothic", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPedirNombre->ForeColor = System::Drawing::Color::White;
			this->lblPedirNombre->Location = System::Drawing::Point(50, 40);
			this->lblPedirNombre->Name = L"lblPedirNombre";
			this->lblPedirNombre->Size = System::Drawing::Size(182, 19);
			this->lblPedirNombre->TabIndex = 2;
			this->lblPedirNombre->Text = L"Ingrese su nombre:";
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(800, 800);
			this->Controls->Add(this->panelNombre);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnCreditos);
			this->Controls->Add(this->btnInstrucciones);
			this->Controls->Add(this->btnJugar);
			this->Controls->Add(this->lblTitulo);
			this->Name = L"MenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Menu Principal";
			this->panelNombre->ResumeLayout(false);
			this->panelNombre->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		

	private: System::Void btnJugar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Mostrar panel para pedir nombre
		panelNombre->Visible = true;
		panelNombre->BringToFront();
		txtNombre->Focus();
	}

	private: System::Void btnGo_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtNombre->Text != "") {
			
			panelNombre->Visible = false;

			this->Hide(); 
			MyForm^ nivel1 = gcnew MyForm();
			nivel1->ShowDialog(); 
			this->Show(); 
		}
		else {
			MessageBox::Show("Por favor escribe un nombre.");
		}
	}

	private: System::Void btnInstrucciones_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("INSTRUCCIONES:\n\n- Usa W, A, S, D para moverte.\n- Acércate a las terminales para interactuar.\n- Elige 'Cuestionar' para ganar Voluntad.\n- Evita los obstáculos.\n- Objetivo: Consigue 5 puntos de Voluntad.", "Ayuda");
	}

	private: System::Void btnCreditos_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("CRÉDITOS:\n\nDesarrollado por:\n- Tu Nombre\n- Nombre compañero 1\n- Nombre compañero 2\n\nUPC - Algoritmos 2025", "Créditos");
	}

	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	};
}