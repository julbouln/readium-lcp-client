//
//  Created by Artem Brazhnikov on 11/15.
//  Copyright © 2015 Mantano. All rights reserved.
//  Any commercial use is strictly prohibited.
//

#ifndef __ENCRYPTION_PROFILES_MANAGER_H__
#define __ENCRYPTION_PROFILES_MANAGER_H__

#include <map>
#include <memory>
#include "IEncryptionProfile.h"

namespace lcp
{
    class EncryptionProfilesManager
    {
    public:
        EncryptionProfilesManager();
        bool RegisterProfile(std::unique_ptr<IEncryptionProfile> profile);
        IEncryptionProfile * GetProfile(const std::string & name) const;

    private:
        typedef std::map<std::string, std::unique_ptr<IEncryptionProfile> > ProfilesMap;
        ProfilesMap m_profilesMap;
    };
}

#endif //__ENCRYPTION_PROFILES_MANAGER_H__
