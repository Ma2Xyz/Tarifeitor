#pragma once
#include <wx/wx.h>

class mainFrame: public wxFrame {
public:
	mainFrame(const wxString& title);
private:
	enum IDs {
		ejecutarID = 2,
		cancelarID = 3,
		filtroID = 4,
		tamañoColumnasID = 5,
		fuenteID = 6,
		preciosID = 7,
		mayusculasID = 8,
		nombreArchivoID = 9,
		seleccionarArchivoID = 10
	};

	wxString rutaSeleccionada;

	wxTextCtrl* nombreArchivo;
	wxCheckBox* casillaFiltro;
	wxCheckBox* casillaTamañoColumnas;
	wxCheckBox* casillaFuente;
	wxCheckBox* casillaPrecios;
	wxCheckBox* casillaMayusculas;
	void OnButtonClicked(wxCommandEvent& evt);
	void OnSelectFileClicked(wxCommandEvent& evt);
	void OnTextChanged(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

