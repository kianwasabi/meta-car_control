/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.14.v202310241605.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V0_COMMONAPI_Car_Control_STUB_DEFAULT_HPP_
#define V0_COMMONAPI_Car_Control_STUB_DEFAULT_HPP_


#include <CommonAPI/Export.hpp>

#include <v0/commonapi/CarControlStub.hpp>
#include <cassert>
#include <sstream>

# if defined(_MSC_VER)
#  if _MSC_VER >= 1300
/*
 * Diamond inheritance is used for the CommonAPI::Proxy base class.
 * The Microsoft compiler put warning (C4250) using a desired c++ feature: "Delegating to a sister class"
 * A powerful technique that arises from using virtual inheritance is to delegate a method from a class in another class
 * by using a common abstract base class. This is also called cross delegation.
 */
#    pragma warning( disable : 4250 )
#  endif
# endif

namespace v0 {
namespace commonapi {

/**
 * Provides a default implementation for CarControlStubRemoteEvent and
 * CarControlStub. Method callbacks have an empty implementation,
 * remote set calls on attributes will always change the value of the attribute
 * to the one received.
 *
 * Override this stub if you only want to provide a subset of the functionality
 * that would be defined for this service, and/or if you do not need any non-default
 * behaviour.
 */
class COMMONAPI_EXPORT_CLASS_EXPLICIT CarControlStubDefault
    : public virtual CarControlStub {
public:
    COMMONAPI_EXPORT CarControlStubDefault()
        : remoteEventHandler_(this),
          interfaceVersion_(CarControl::getInterfaceVersion()) {
    }

    COMMONAPI_EXPORT const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> _client) {
        (void)_client;
        return interfaceVersion_;
    }

    COMMONAPI_EXPORT CarControlStubRemoteEvent* initStubAdapter(const std::shared_ptr< CarControlStubAdapter> &_adapter) {
        CommonAPI::Stub<CarControlStubAdapter, CarControlStubRemoteEvent>::stubAdapter_ = _adapter;
        return &remoteEventHandler_;
    }

    COMMONAPI_EXPORT virtual const std::string &getIndicatorAttribute() {
        return indicatorAttributeValue_;
    }
    COMMONAPI_EXPORT virtual const std::string &getIndicatorAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) {
        (void)_client;
        return getIndicatorAttribute();
    }
    COMMONAPI_EXPORT virtual void setIndicatorAttribute(std::string _value) {
        const bool valueChanged = trySetIndicatorAttribute(std::move(_value));
        if (valueChanged) {
            fireIndicatorAttributeChanged(indicatorAttributeValue_);
        }
    }
    COMMONAPI_EXPORT virtual const std::string &getGearAttribute() {
        return gearAttributeValue_;
    }
    COMMONAPI_EXPORT virtual const std::string &getGearAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) {
        (void)_client;
        return getGearAttribute();
    }
    COMMONAPI_EXPORT virtual void setGearAttribute(std::string _value) {
        const bool valueChanged = trySetGearAttribute(std::move(_value));
        if (valueChanged) {
            fireGearAttributeChanged(gearAttributeValue_);
        }
    }
    COMMONAPI_EXPORT virtual void gearSelectionHeadUnit(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _selectedGear, gearSelectionHeadUnitReply_t _reply) {
        (void)_client;
        (void)_selectedGear;
        bool accepte = false;
        _reply(accepte);
    }


protected:
    COMMONAPI_EXPORT virtual bool trySetIndicatorAttribute(std::string _value) {
        if (!validateIndicatorAttributeRequestedValue(_value))
            return false;

        bool valueChanged;
        std::shared_ptr<CarControlStubAdapter> stubAdapter = CommonAPI::Stub<CarControlStubAdapter, CarControlStubRemoteEvent>::stubAdapter_.lock();
        if(stubAdapter) {
            stubAdapter->lockIndicatorAttribute(true);
            valueChanged = (indicatorAttributeValue_ != _value);
            indicatorAttributeValue_ = std::move(_value);
            stubAdapter->lockIndicatorAttribute(false);
        } else {
            valueChanged = (indicatorAttributeValue_ != _value);
            indicatorAttributeValue_ = std::move(_value);
        }

       return valueChanged;
    }
    COMMONAPI_EXPORT virtual bool validateIndicatorAttributeRequestedValue(const std::string &_value) {
        (void)_value;
        return true;
    }
    COMMONAPI_EXPORT virtual bool trySetGearAttribute(std::string _value) {
        if (!validateGearAttributeRequestedValue(_value))
            return false;

        bool valueChanged;
        std::shared_ptr<CarControlStubAdapter> stubAdapter = CommonAPI::Stub<CarControlStubAdapter, CarControlStubRemoteEvent>::stubAdapter_.lock();
        if(stubAdapter) {
            stubAdapter->lockGearAttribute(true);
            valueChanged = (gearAttributeValue_ != _value);
            gearAttributeValue_ = std::move(_value);
            stubAdapter->lockGearAttribute(false);
        } else {
            valueChanged = (gearAttributeValue_ != _value);
            gearAttributeValue_ = std::move(_value);
        }

       return valueChanged;
    }
    COMMONAPI_EXPORT virtual bool validateGearAttributeRequestedValue(const std::string &_value) {
        (void)_value;
        return true;
    }
    class COMMONAPI_EXPORT_CLASS_EXPLICIT RemoteEventHandler: public virtual CarControlStubRemoteEvent {
    public:
        COMMONAPI_EXPORT RemoteEventHandler(CarControlStubDefault *_defaultStub)
            : 
              defaultStub_(_defaultStub) {
        }


    private:
        CarControlStubDefault *defaultStub_;
    };
protected:
    CarControlStubDefault::RemoteEventHandler remoteEventHandler_;

private:

    std::string indicatorAttributeValue_ {};
    std::string gearAttributeValue_ {};

    CommonAPI::Version interfaceVersion_;
};

} // namespace commonapi
} // namespace v0


// Compatibility
namespace v0_1 = v0;

#endif // V0_COMMONAPI_Car_Control_STUB_DEFAULT
