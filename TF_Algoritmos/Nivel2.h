#pragma once
#include "ControladoraNivel2.h"

namespace TFAlgoritmos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Nivel2 : public System::Windows::Forms::Form
	{
	public:
		Nivel2(void)
		{
			InitializeComponent();
			juego = gcnew ControladoraNivel2();
		}

	protected:
		~Nivel2()
		{
			if (components) delete components;
		}

	private:
		ControladoraNivel2^ juego;
		bool w, s, a, d;
		System::Windows::Forms::Timer^ timer1;
		System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 30;
			this->timer1->Tick += gcnew System::EventHandler(this, &Nivel2::timer1_Tick);
			// 
			// Nivel2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 800);
			this->DoubleBuffered = true;
			this->Name = L"Nivel2";
			this->Text = L"Acto II: La Luz del Pensamiento";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel2::Nivel2_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel2::Nivel2_KeyUp);
			this->ResumeLayout(false);
		}
#pragma endregion

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);

		juego->MoverTodo(w, s, a, d);
		juego->DibujarTodo(buffer->Graphics);

		buffer->Render(g);
		delete buffer; delete espacio; delete g;
	}

	private: System::Void Nivel2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::W) w = true;
		if (e->KeyCode == Keys::S) s = true;
		if (e->KeyCode == Keys::A) a = true;
		if (e->KeyCode == Keys::D) d = true;
	}

	private: System::Void Nivel2_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::W) w = false;
		if (e->KeyCode == Keys::S) s = false;
		if (e->KeyCode == Keys::A) a = false;
		if (e->KeyCode == Keys::D) d = false;
	}
	};
}