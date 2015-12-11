//
//  Created by Mickaël Menu, Artem Brazhnikov on 11/15.
//  Copyright © 2015 Mantano. All rights reserved.
//  Any commercial use is strictly prohibited.
//

#ifndef __I_ACQUISTION_CALLBACK_H__
#define __I_ACQUISTION_CALLBACK_H__

#include "LcpStatus.h"

namespace lcp
{
    class IAcquisition;

    class IAcquisitionCallback
    {
    public:
        virtual void OnAcquisitionStarted(IAcquisition * acquisition) = 0;
        virtual void OnAcquisitionProgressed(IAcquisition * acquisition, float progress) = 0;
        virtual void OnAcquisitionCanceled(IAcquisition * acquisition) = 0;
        virtual void OnAcquisitionEnded(IAcquisition * acquisition, Status result) = 0;
        virtual ~IAcquisitionCallback() {}
    };
}

#endif //__I_ACQUISTION_CALLBACK_H__
