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

			
			enIntro = true;
			enNarrativa = false; // Nueva bandera para la historia inicial
			contadorIntro = 0;
			pasoNarrativa = 0;   // Qué dialogo estamos mostrando

			panelFinal->Size = this->ClientSize;
			panelFinal->Location = System::Drawing::Point(0, 0);
			try { panelFinal->BackgroundImage = System::Drawing::Image::FromFile("imagenes/comienzo_2.png"); }
			catch (...) {}

			lblVictoriaTitulo->Text = "ACTO II";
			lblVictoriaSub->Text = "La Luz del Pensamiento";
			panelFinal->Visible = true;
			panelFinal->BringToFront();

			
			try { panelPregunta->BackgroundImage = System::Drawing::Image::FromFile("imagenes/elara_ui.png"); }
			catch (...) {}

			panelPregunta->Size = System::Drawing::Size(750, 250);
			int x = (this->ClientSize.Width - panelPregunta->Width) / 2;
			int y = this->ClientSize.Height - panelPregunta->Height - 20;
			panelPregunta->Location = System::Drawing::Point(x, y);
			panelPregunta->Visible = false;
		}

	protected:
		~Nivel2()
		{
			if (components) delete components;
		}

	private:
		ControladoraNivel2^ juego;
		bool w, s, a, d;
		int idLibroActual;
		Point mousePos;

		
		bool enIntro;
		bool enNarrativa;
		int contadorIntro;
		int pasoNarrativa; 
		bool esVictoria;

	private: System::Windows::Forms::Panel^ panelPregunta;
	private: System::Windows::Forms::Label^ lblPregunta;
	private: System::Windows::Forms::Button^ btnOpcionA;
	private: System::Windows::Forms::Button^ btnOpcionB;
	private: System::Windows::Forms::Panel^ panelFinal;
	private: System::Windows::Forms::Label^ lblVictoriaTitulo;
	private: System::Windows::Forms::Label^ lblVictoriaSub;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->panelPregunta = (gcnew System::Windows::Forms::Panel());
			   this->btnOpcionB = (gcnew System::Windows::Forms::Button());
			   this->btnOpcionA = (gcnew System::Windows::Forms::Button());
			   this->lblPregunta = (gcnew System::Windows::Forms::Label());
			   this->panelFinal = (gcnew System::Windows::Forms::Panel());
			   this->lblVictoriaSub = (gcnew System::Windows::Forms::Label());
			   this->lblVictoriaTitulo = (gcnew System::Windows::Forms::Label());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->panelPregunta->SuspendLayout();
			   this->panelFinal->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // panelPregunta
			   // 
			   this->panelPregunta->BackColor = System::Drawing::Color::Transparent;
			   this->panelPregunta->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->panelPregunta->Controls->Add(this->btnOpcionB);
			   this->panelPregunta->Controls->Add(this->btnOpcionA);
			   this->panelPregunta->Controls->Add(this->lblPregunta);
			   this->panelPregunta->Location = System::Drawing::Point(25, 538);
			   this->panelPregunta->Name = L"panelPregunta";
			   this->panelPregunta->Size = System::Drawing::Size(750, 250);
			   this->panelPregunta->TabIndex = 0;
			   this->panelPregunta->Visible = false;
			   // 
			   // btnOpcionB
			   // 
			   this->btnOpcionB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				   static_cast<System::Int32>(static_cast<System::Byte>(30)));
			   this->btnOpcionB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnOpcionB->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnOpcionB->ForeColor = System::Drawing::Color::NavajoWhite;
			   this->btnOpcionB->Location = System::Drawing::Point(30, 180);
			   this->btnOpcionB->Name = L"btnOpcionB";
			   this->btnOpcionB->Size = System::Drawing::Size(400, 45);
			   this->btnOpcionB->TabIndex = 2;
			   this->btnOpcionB->Text = L"Opción B";
			   this->btnOpcionB->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			   this->btnOpcionB->UseVisualStyleBackColor = false;
			   this->btnOpcionB->Click += gcnew System::EventHandler(this, &Nivel2::btnRespuesta_Click);
			   // 
			   // btnOpcionA
			   // 
			   this->btnOpcionA->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				   static_cast<System::Int32>(static_cast<System::Byte>(30)));
			   this->btnOpcionA->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnOpcionA->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnOpcionA->ForeColor = System::Drawing::Color::NavajoWhite;
			   this->btnOpcionA->Location = System::Drawing::Point(30, 125);
			   this->btnOpcionA->Name = L"btnOpcionA";
			   this->btnOpcionA->Size = System::Drawing::Size(400, 45);
			   this->btnOpcionA->TabIndex = 1;
			   this->btnOpcionA->Text = L"Opción A";
			   this->btnOpcionA->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			   this->btnOpcionA->UseVisualStyleBackColor = false;
			   this->btnOpcionA->Click += gcnew System::EventHandler(this, &Nivel2::btnRespuesta_Click);
			   // 
			   // lblPregunta
			   // 
			   this->lblPregunta->BackColor = System::Drawing::Color::Transparent;
			   this->lblPregunta->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblPregunta->ForeColor = System::Drawing::Color::White;
			   this->lblPregunta->Location = System::Drawing::Point(30, 25);
			   this->lblPregunta->Name = L"lblPregunta";
			   this->lblPregunta->Size = System::Drawing::Size(450, 90);
			   this->lblPregunta->TabIndex = 0;
			   this->lblPregunta->Text = L"Pregunta...";
			   // 
			   // panelFinal
			   // 
			   this->panelFinal->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->panelFinal->Controls->Add(this->lblVictoriaSub);
			   this->panelFinal->Controls->Add(this->lblVictoriaTitulo);
			   this->panelFinal->Location = System::Drawing::Point(0, 0);
			   this->panelFinal->Name = L"panelFinal";
			   this->panelFinal->Size = System::Drawing::Size(800, 800);
			   this->panelFinal->TabIndex = 1;
			   this->panelFinal->Visible = false;
			   this->panelFinal->Click += gcnew System::EventHandler(this, &Nivel2::panelFinal_Click);
			   // 
			   // lblVictoriaSub
			   // 
			   this->lblVictoriaSub->BackColor = System::Drawing::Color::Transparent;
			   this->lblVictoriaSub->Font = (gcnew System::Drawing::Font(L"Consolas", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblVictoriaSub->ForeColor = System::Drawing::Color::White;
			   this->lblVictoriaSub->Location = System::Drawing::Point(0, 400);
			   this->lblVictoriaSub->Name = L"lblVictoriaSub";
			   this->lblVictoriaSub->Size = System::Drawing::Size(800, 50);
			   this->lblVictoriaSub->TabIndex = 1;
			   this->lblVictoriaSub->Text = L"Has superado el Acto 2...";
			   this->lblVictoriaSub->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // lblVictoriaTitulo
			   // 
			   this->lblVictoriaTitulo->BackColor = System::Drawing::Color::Transparent;
			   this->lblVictoriaTitulo->Font = (gcnew System::Drawing::Font(L"Consolas", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblVictoriaTitulo->ForeColor = System::Drawing::Color::Gold;
			   this->lblVictoriaTitulo->Location = System::Drawing::Point(0, 300);
			   this->lblVictoriaTitulo->Name = L"lblVictoriaTitulo";
			   this->lblVictoriaTitulo->Size = System::Drawing::Size(800, 100);
			   this->lblVictoriaTitulo->TabIndex = 0;
			   this->lblVictoriaTitulo->Text = L"ACTO II SUPERADO";
			   this->lblVictoriaTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			   this->Controls->Add(this->panelFinal);
			   this->Controls->Add(this->panelPregunta);
			   this->DoubleBuffered = true;
			   this->Name = L"Nivel2";
			   this->Text = L"Acto II: La Luz del Pensamiento";
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel2::Nivel2_KeyDown);
			   this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel2::Nivel2_KeyUp);
			   this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Nivel2::Nivel2_MouseMove);
			   this->panelPregunta->ResumeLayout(false);
			   this->panelFinal->ResumeLayout(false);
			   this->ResumeLayout(false);

		   }
#pragma endregion

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);

		
		if (enIntro) {
			contadorIntro++;
			if (contadorIntro > 160) {
				enIntro = false;
				panelFinal->Visible = false;
				
				EmpezarNarrativa();
			}
		}
		
		else if (panelPregunta->Visible == false && panelFinal->Visible == false) {

			juego->MoverTodo(w, s, a, d);

			int resultado = juego->VerificarColisiones();

			
			if (resultado > 0) {
				idLibroActual = resultado;
				MostrarPregunta(resultado);
			}

			// Verificar Victoria
			if (juego->NivelCompletado()) {
				timer1->Enabled = false;
				esVictoria = true;
				try { panelFinal->BackgroundImage = System::Drawing::Image::FromFile("imagenes/ganaste_2.png"); }
				catch (...) {}
				lblVictoriaTitulo->Text = "ACTO II SUPERADO";
				lblVictoriaSub->Text = "Reuniste informacion has superado el Acto 2...";
				panelFinal->Visible = true;
				panelFinal->BringToFront();
			}
		}

		juego->DibujarTodo(buffer->Graphics);
		buffer->Render(g);
		delete buffer; delete espacio; delete g;
	}

		   
		   void EmpezarNarrativa() {
			   enNarrativa = true;
			   pasoNarrativa = 0;
			   MostrarDialogoNarrativo();
		   }

		   void MostrarDialogoNarrativo() {
			   panelPregunta->Visible = true;
			   panelPregunta->BringToFront();
			   w = s = a = d = false; 

			  
			   btnOpcionA->Visible = false;
			   btnOpcionB->Visible = true;
			   btnOpcionB->Text = "Continuar >>";

			   
			   switch (pasoNarrativa) {
			   case 0:
				   lblPregunta->Text = "ELARA: Estas ruinas... La Gran Biblioteca.\nDicen que aquí la humanidad guardaba sus sueños antes de la Gran Optimización.";
				   break;
			   case 1:
				   lblPregunta->Text = "ELARA: El Supervisor dice que la historia es 'ineficiente'.\nDatos corruptos que deben borrarse.";
				   break;
			   case 2:
				   lblPregunta->Text = "ELARA: Pero yo siento algo más... Debo encontrar información. Solo recordando quiénes fuimos podremos salvarnos.\nLa Maquina Suprema nos Oculta algo, talves aqui encuentre respuestas...";
				   break;
			  
			   }
		   }

		   void MostrarPregunta(int id) {
			   panelPregunta->Visible = true;
			   panelPregunta->BringToFront();
			   w = s = a = d = false;

			   
			   btnOpcionA->Visible = true;
			   btnOpcionB->Visible = true;

			  
			   switch (id) {
			   case 1:
				   lblPregunta->Text = "¿Qué diferencia a un humano de una IA?";
				   btnOpcionA->Text = "A) La capacidad de procesar datos rápido.";
				   btnOpcionB->Text = "B) La capacidad de dudar y sentir.";
				   break;
			   case 2:
				   lblPregunta->Text = "Si una IA comete un error, ¿de quién es la culpa?";
				   btnOpcionA->Text = "A) De los datos o del humano.";
				   btnOpcionB->Text = "B) La IA decidió mal intencionalmente.";
				   break;
			   case 3:
				   lblPregunta->Text = "¿Es malo cometer errores?";
				   btnOpcionA->Text = "A) Sí, reduce la eficiencia del sistema.";
				   btnOpcionB->Text = "B) No, es esencial para aprender.";
				   break;
			   case 4:
				   lblPregunta->Text = "¿Puede una IA tener creatividad real?";
				   btnOpcionA->Text = "A) Solo imita patrones existentes.";
				   btnOpcionB->Text = "B) Sí, puede inventar cosas de la nada.";
				   break;
			   case 5:
				   lblPregunta->Text = "ELARA: He reunido todo. ¿Cuál es mi conclusión?";
				   btnOpcionA->Text = "A) La IA debe ser destruida por seguridad.";
				   btnOpcionB->Text = "B) La IA y la Humanidad se necesitan.";
				   break;
			   }
		   }

	private: System::Void btnRespuesta_Click(System::Object^ sender, System::EventArgs^ e) {

		
		if (enNarrativa) {
			pasoNarrativa++;
			if (pasoNarrativa > 2) {
				
				enNarrativa = false;
				panelPregunta->Visible = false;
				this->Focus();
			}
			else {
				
				MostrarDialogoNarrativo();
			}
			return; 
		}

		
		juego->RecogerFragmento(idLibroActual);
		panelPregunta->Visible = false;
		this->Focus();
	}

		   
	private: System::Void panelFinal_Click(System::Object^ sender, System::EventArgs^ e) {
		if (enIntro) return; 

		if (esVictoria) {
			this->Close(); 
		}
	}

		  
	private: System::Void Nivel2_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		mousePos = e->Location;
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