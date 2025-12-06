#pragma once
#include "Escenario.h"
#include "Kael.h"
#include "Terminal.h"
#include <vector>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;

namespace TFAlgoritmos {
    public ref class Controladora {
    private:
        Escenario^ escenario;
        Kael^ kael;
        List<Terminal^>^ terminales;
        List<Rectangle>^ obstaculos;
        Rectangle areaSupervisor;

        // Variables de Camara
        int camX, camY;

    public:
        Controladora() {
            escenario = gcnew Escenario();
            
            kael = gcnew Kael(1200, 1200);
            terminales = gcnew List<Terminal^>();
            obstaculos = gcnew List<Rectangle>();

            
            areaSupervisor = Rectangle(980, 980, 100, 100);

          

            obstaculos->Add(Rectangle(1012, 1012, 40, 40)); 

            // Bordes
            obstaculos->Add(Rectangle(0, 0, 1600, 120));
            obstaculos->Add(Rectangle(0, 0, 50, 1600));
            obstaculos->Add(Rectangle(1554, 46, 100, 1600));
            obstaculos->Add(Rectangle(0, 1500, 1600, 100));

            // Zonas internas 
            obstaculos->Add(Rectangle(350, 30, 330, 310));
            obstaculos->Add(Rectangle(580, 30, 330, 220));

            obstaculos->Add(Rectangle(916, 100, 24, 300));
            obstaculos->Add(Rectangle(1042, 100, 24, 140));
            obstaculos->Add(Rectangle(1236, 100, 24, 140));
            obstaculos->Add(Rectangle(1428, 100, 24, 140));

            obstaculos->Add(Rectangle(1508, 410, 46, 160));
            obstaculos->Add(Rectangle(1360, 540, 20, 20));
            obstaculos->Add(Rectangle(1108, 488, 154, 80));

            obstaculos->Add(Rectangle(50, 1240, 830, 360)); 

            obstaculos->Add(Rectangle(788, 600, 800, 420)); 
            obstaculos->Add(Rectangle(788, 540, 150, 100));

            obstaculos->Add(Rectangle(150, 914, 154, 60));
            obstaculos->Add(Rectangle(470, 580, 154, 60));
            obstaculos->Add(Rectangle(1500, 1100, 46, 400));

            // --- TERMINALES (x2) ---
            terminales->Add(gcnew Terminal(200, 120, 1));
            terminales->Add(gcnew Terminal(750, 240, 2));
            terminales->Add(gcnew Terminal(1032, 220, 3));
            terminales->Add(gcnew Terminal(1418, 220, 4));
            terminales->Add(gcnew Terminal(820, 1000, 5));
        }

        void MoverTodo(bool w, bool s, bool a, bool d) {
            escenario->Animar();
            
            kael->Mover(w, s, a, d, 1600, 1600, obstaculos);

            
            camX = kael->GetX() - 400 + (kael->GetRectangulo().Width / 2);
            camY = kael->GetY() - 400 + (kael->GetRectangulo().Height / 2);

            // Clamping limites camaraaaaaaa
            if (camX < 0) camX = 0;
            if (camY < 0) camY = 0;
            if (camX > 1600 - 800) camX = 800;
            if (camY > 1600 - 800) camY = 800;
        }

        void DibujarTodo(Graphics^ g) {
            escenario->Dibujar(g, camX, camY); 

            for (int i = 0; i < terminales->Count; i++) {
                terminales[i]->Dibujar(g, camX, camY); 
            }

            kael->Dibujar(g, camX, camY); 

           
        }

        int VerificarColisionNivel1() {
            for (int i = 0; i < terminales->Count; i++) {
                if (terminales[i]->activa) {
                    if (kael->GetRectangulo().IntersectsWith(terminales[i]->GetRectangulo())) {
                        return terminales[i]->id;
                    }
                }
            }
            return 0;
        }

        bool VerificarColisionSupervisor() {
            return kael->GetRectangulo().IntersectsWith(areaSupervisor);
        }

        void ResolverInteraccion(int id) {
            kael->AumentarVoluntad();
            for (int i = 0; i < terminales->Count; i++) {
                if (terminales[i]->id == id) {
                    terminales[i]->Desactivar();
                    break;
                }
            }
        }

        int GetVoluntadKael() { return kael->GetVoluntad(); }

       
        int GetCamX() { return camX; }
        int GetCamY() { return camY; }
    };
}