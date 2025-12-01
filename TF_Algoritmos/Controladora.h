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

    public:
        Controladora() {
            escenario = gcnew Escenario();
            // donde inicia kael
            kael = gcnew Kael(600, 600);
            terminales = gcnew List<Terminal^>();
            obstaculos = gcnew List<Rectangle>();

           
            areaSupervisor = Rectangle(490, 490, 50, 50);

			// obstaculos (rectangulos)
            obstaculos->Add(Rectangle(506, 506, 20, 20)); 

            
            obstaculos->Add(Rectangle(0, 0, 800, 60));
            obstaculos->Add(Rectangle(0, 0, 25, 800));
            obstaculos->Add(Rectangle(777, 23, 50, 800));
            obstaculos->Add(Rectangle(0, 750, 800, 50));
            obstaculos->Add(Rectangle(175, 15, 165, 155));
            obstaculos->Add(Rectangle(290, 15, 165, 110));
            obstaculos->Add(Rectangle(458, 50, 12, 150));
            obstaculos->Add(Rectangle(521, 50, 12, 70));
            obstaculos->Add(Rectangle(618, 50, 12, 70));
            obstaculos->Add(Rectangle(714, 50, 12, 70));
            obstaculos->Add(Rectangle(754, 205, 23, 80));
            obstaculos->Add(Rectangle(680, 270, 10, 10));
            obstaculos->Add(Rectangle(554, 244, 77, 40));
            obstaculos->Add(Rectangle(25, 620, 415, 180));
            obstaculos->Add(Rectangle(394, 300, 400, 210));
            obstaculos->Add(Rectangle(394, 270, 75, 50));
            obstaculos->Add(Rectangle(75, 457, 77, 30));
            obstaculos->Add(Rectangle(235, 290, 77, 30));
            obstaculos->Add(Rectangle(750, 550, 23, 200));

            // TERMINALES
            terminales->Add(gcnew Terminal(100, 60, 1));
            terminales->Add(gcnew Terminal(375, 120, 2));
            terminales->Add(gcnew Terminal(516, 110, 3));
            terminales->Add(gcnew Terminal(709, 110, 4));
            terminales->Add(gcnew Terminal(410, 500, 5));
        }

        void MoverTodo(bool w, bool s, bool a, bool d) {
            escenario->Animar();
            kael->Mover(w, s, a, d, 800, 800, obstaculos);
        }

        void DibujarTodo(Graphics^ g) {
            escenario->Dibujar(g);
            for (int i = 0; i < terminales->Count; i++) {
                terminales[i]->Dibujar(g);
            }
            kael->Dibujar(g);

         
        }

        int VerificarColision() {
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
    };
}