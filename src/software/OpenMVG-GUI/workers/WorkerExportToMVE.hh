// This file is part of OpenMVG, an Open Multiple View Geometry C++ library.

// Copyright (c) 2017 Romuald PERROT.

// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef _OPENMVG_SOFTWARE_OPENMVG_GUI_WORKERS_WORKER_EXPORT_TO_MVE_HH_
#define _OPENMVG_SOFTWARE_OPENMVG_GUI_WORKERS_WORKER_EXPORT_TO_MVE_HH_

#include "WorkerInterface.hh"

#include "openMVG/sfm/sfm_data.hpp"

#include <QObject>

#include <atomic>
#include <string>

namespace openMVG_gui
{

class WorkerExportToMVE : public QObject, public WorkerInterface
{
  public:
    WorkerExportToMVE( std::shared_ptr<openMVG::sfm::SfM_Data> sfm_data, const std::string &output_folder );

    /**
     * @brief get progress range
     */
    void progressRange( int &min, int &max ) const;

  public slots:

    /**
     * @brief Do the computation
     */
    void process( void );

    /**
     * @brief internal progress bar has been incremented, now signal it to the external progress dialog
     */
    void hasIncremented( int );

    /**
     * @brief Send progress signal
     */
    void sendProgress( void );

  signals:

    // 0 -> nothing done
    // n -> all done (n : number of images)
    void progress( int );

    // After computation of all features (ie: signal to clear memory)
    void finished( const WorkerNextAction &na );

  private:
    // Internal counter for the number of step already done
    std::atomic<unsigned int> m_progress_value;

    std::shared_ptr<openMVG::sfm::SfM_Data> m_sfm_data;
    std::string m_out_MVE_folder;

    Q_OBJECT
};

} // namespace openMVG_gui

#endif