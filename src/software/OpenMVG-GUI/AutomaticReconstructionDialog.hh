#ifndef _OPENMVG_SOFTWARE_OPENMVG_GUI_AUTOMATIC_RECONSTRUCTION_DIALOG_HH_
#define _OPENMVG_SOFTWARE_OPENMVG_GUI_AUTOMATIC_RECONSTRUCTION_DIALOG_HH_

#include <QComboBox>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>


namespace openMVG_gui
{

/**
* @brief Preset for automatic reconstruction
*/
enum AutomaticReconstructionPreset
{
  AUTOMATIC_RECONSTRUCTION_PRESET_NORMAL ,
  AUTOMATIC_RECONSTRUCTION_PRESET_HIGH ,
  AUTOMATIC_RECONSTRUCTION_PRESET_ULTRA
} ;

/**
* @brief Dialog managing a full project computation from an input image folder
*/
class AutomaticReconstructionDialog : public QDialog
{
  public:

    /**
    * @brief Ctr
    * @param parent Parent widget
    */
    AutomaticReconstructionDialog( QWidget * parent ) ;

    /**
    * @brief Path of the input image
    */
    std::string inputImagePath( void ) const ;

    /**
    * @brief Path of the output project
    */
    std::string outputProjectPath( void ) const ;

    /**
    * @brief Reconstruction preset selected
    */
    AutomaticReconstructionPreset preset( void ) const ;

  public slots :

    /**
    * @brief action to be executed when user click on cancel button
    */
    void onCancel( void ) ;

    /**
    * @brief action to be executed when user click on OK button
    */
    void onOk( void ) ;

    /**
    * @brief action to be executed when user want to select output folder
    */
    void onWantToSelectProjectPath( void ) ;

    /**
    * @brief action to be executed when user want to select input image folder
    */
    void onWantToSelectImagePath( void ) ;


  private:

    /**
    * @brief Build interface widgets
    */
    void BuildInterface( void ) ;

    /**
    * @brief Make connections between elements
    */
    void MakeConnections( void ) ;

    QLabel * m_input_folder_lbl ;
    QLineEdit * m_input_folder_line ;
    QPushButton * m_input_folder_btn ;

    QLabel * m_output_project_folder_lbl ;
    QLineEdit * m_output_project_folder_line ;
    QPushButton * m_output_project_folder_btn ;

    QLabel * m_feature_preset_lbl ;
    QComboBox * m_feature_preset_combo ;

    QLabel * m_matching_preset_lbl ;
    QComboBox * m_matching_preset_combo ;

    QPushButton * m_btn_cancel ;
    QPushButton * m_btn_ok ;

    Q_OBJECT
} ;

} // namespace openMVG_gui

#endif