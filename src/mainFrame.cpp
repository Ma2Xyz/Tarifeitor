#include "../headers/mainFrame.h"
#include <wx/wx.h>
#include <map>
#include <iostream>
#include <cstdio>
using namespace std;

wxBEGIN_EVENT_TABLE(mainFrame, wxFrame)
	EVT_BUTTON(ejecutarID, mainFrame::OnButtonClicked)
	EVT_BUTTON(seleccionarArchivoID, mainFrame::OnSelectFileClicked)
	EVT_TEXT(nombreArchivoID, mainFrame::OnTextChanged)
wxEND_EVENT_TABLE()

mainFrame::mainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);

	wxStaticText* textoParametros = new wxStaticText(panel, wxID_ANY, "Parametros", wxPoint(120, 10));

	casillaFiltro = new wxCheckBox(panel, filtroID, "Filtro", wxPoint(35, 25), wxDefaultSize);
	casillaTamañoColumnas = new wxCheckBox(panel, tamañoColumnasID, "Columnas", wxPoint(35, 60));
	casillaFuente = new wxCheckBox(panel, fuenteID, "Fuente", wxPoint(35, 95));
	casillaPrecios = new wxCheckBox(panel, preciosID, "Propiedades de numeros", wxPoint(210, 25));
	casillaMayusculas = new wxCheckBox(panel, mayusculasID, "Mayusculas", wxPoint(210, 60));

	casillaFiltro->SetValue(true);
	casillaTamañoColumnas->SetValue(true);
	casillaFuente->SetValue(true);
	casillaPrecios->SetValue(true);
	casillaMayusculas->SetValue(true);

	nombreArchivo = new wxTextCtrl(panel, nombreArchivoID, "Ruta del Archivo", wxPoint(210, 95));
	wxButton* botonSeleccionarArchivo = new wxButton(panel, seleccionarArchivoID, "...", wxPoint(320, 95), wxSize(30, 23));

	wxButton* botonEjecutar = new wxButton(panel, ejecutarID, "Ejecutar", wxPoint(285, 130), wxSize(80, 32));


	wxButton* botonCancelar = new wxButton(panel, cancelarID, "Cancelar", wxPoint(5, 130), wxSize(80, 32));

	CreateStatusBar();
}

void mainFrame::OnSelectFileClicked(wxCommandEvent& evt) {
	wxFileDialog openFileDialog(this, "Seleccionar archivo", "", "", "Todos los archivos (*.*)|*.*", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if (openFileDialog.ShowModal() == wxID_CANCEL) {
		// El usuario canceló la selección
		return;
	}

	rutaSeleccionada = openFileDialog.GetPath();
	nombreArchivo->SetValue(rutaSeleccionada);
}

void mainFrame::OnTextChanged(wxCommandEvent& evt) {
	rutaSeleccionada = evt.GetString();
}

void mainFrame::OnButtonClicked(wxCommandEvent& evt) {
	string comando = "python scripts\\Tarifeitor.py " + rutaSeleccionada.ToStdString() + " -";

	std::map<char, wxCheckBox*> letraCasillaMap;
	letraCasillaMap['R'] = casillaFiltro;
	letraCasillaMap['T'] = casillaTamañoColumnas;
	letraCasillaMap['F'] = casillaFuente;
	letraCasillaMap['P'] = casillaPrecios;
	letraCasillaMap['M'] = casillaMayusculas;

	for (const auto& pair : letraCasillaMap) {
		char letra = pair.first;
		wxCheckBox* casilla = pair.second;
		if (casilla->IsChecked()) {
			comando += letra;
		}
	}
	wxLogStatus("Aplicando cambios...");
	system(comando.c_str());

	FILE* pipe = _popen(comando.c_str(), "r");

	if (pipe) {
		char buffer[128];
		while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
			wxLogMessage(buffer);
		}

		_pclose(pipe);
	}
	wxLogStatus("Hecho");
}
