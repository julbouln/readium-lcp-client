//
//  Created by Mickaël Menu, Artem Brazhnikov on 11/15.
//  Copyright © 2015 Mantano. All rights reserved.
//  Any commercial use is strictly prohibited.
//

#ifndef __I_LCP_LINKS_H__
#define __I_LCP_LINKS_H__

#include <vector>
#include <string>
#include "LcpStatus.h"
#include "IValueIterator.h"

namespace lcp
{
    struct Link
    {
        Link()
        {
            templated = false;
            length = 0;
        }
        std::string href;
        std::string title;
        std::string type;
        std::string hash;
        bool templated;
        int length;
    };

    class ILinks
    {
    public:
        virtual IKeyValueIterator<std::string, Link> * Enumerate() const = 0;
        virtual bool Has(const std::string & name) const = 0;
        virtual bool GetLink(const std::string & name, Link & link) const = 0;
        virtual bool HasMany(const std::string & name) const = 0;
        virtual bool GetLinks(const std::string & name, std::vector<Link> & links) const = 0;
        virtual ~ILinks() {}
    };

    static const char * Publication = "publication";
    static const char * Hint = "hint";
    static const char * Self = "self";
}

#endif //__I_LCP_LINKS_H__
