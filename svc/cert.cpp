// **********************************************************************
//
// Copyright (c) 2003-2017 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.7.0
//
// <auto-generated>
//
// Generated from file `cert.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include "cert.h"
#include <IceUtil/PushDisableWarnings.h>
#include <Ice/LocalException.h>
#include <Ice/ValueFactory.h>
#include <Ice/OutgoingAsync.h>
#include <Ice/InputStream.h>
#include <Ice/OutputStream.h>
#include <IceUtil/PopDisableWarnings.h>

#if defined(_MSC_VER)
#   pragma warning(disable:4458) // declaration of ... hides class member
#elif defined(__clang__)
#   pragma clang diagnostic ignored "-Wshadow"
#elif defined(__GNUC__)
#   pragma GCC diagnostic ignored "-Wshadow"
#endif

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 307
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 0
#       error Ice patch level mismatch!
#   endif
#endif

#ifdef ICE_CPP11_MAPPING // C++11 mapping

namespace
{

const ::std::string iceC_Demo_Printer_ids[2] =
{
    "::Demo::Printer",
    "::Ice::Object"
};
const ::std::string iceC_Demo_Printer_ops[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "printString"
};
const ::std::string iceC_Demo_Printer_printString_name = "printString";

}

bool
Demo::Printer::ice_isA(::std::string s, const ::Ice::Current&) const
{
    return ::std::binary_search(iceC_Demo_Printer_ids, iceC_Demo_Printer_ids + 2, s);
}

::std::vector<::std::string>
Demo::Printer::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector<::std::string>(&iceC_Demo_Printer_ids[0], &iceC_Demo_Printer_ids[2]);
}

::std::string
Demo::Printer::ice_id(const ::Ice::Current&) const
{
    return ice_staticId();
}

const ::std::string&
Demo::Printer::ice_staticId()
{
    static const ::std::string typeId = "::Demo::Printer";
    return typeId;
}

bool
Demo::Printer::_iceD_printString(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    auto istr = inS.startReadParams();
    ::std::string iceP_s;
    istr->readAll(iceP_s);
    inS.endReadParams();
    this->printString(::std::move(iceP_s), current);
    inS.writeEmptyParams();
    return true;
}

bool
Demo::Printer::_iceDispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair<const ::std::string*, const ::std::string*> r = ::std::equal_range(iceC_Demo_Printer_ops, iceC_Demo_Printer_ops + 5, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - iceC_Demo_Printer_ops)
    {
        case 0:
        {
            return _iceD_ice_id(in, current);
        }
        case 1:
        {
            return _iceD_ice_ids(in, current);
        }
        case 2:
        {
            return _iceD_ice_isA(in, current);
        }
        case 3:
        {
            return _iceD_ice_ping(in, current);
        }
        case 4:
        {
            return _iceD_printString(in, current);
        }
        default:
        {
            assert(false);
            throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
        }
    }
}

void
Demo::PrinterPrx::_iceI_printString(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>& outAsync, const ::std::string& iceP_s, const ::Ice::Context& context)
{
    outAsync->invoke(iceC_Demo_Printer_printString_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
        [&](::Ice::OutputStream* ostr)
        {
            ostr->writeAll(iceP_s);
        },
        nullptr);
}

::std::shared_ptr<::Ice::ObjectPrx>
Demo::PrinterPrx::_newInstance() const
{
    return ::IceInternal::createProxy<PrinterPrx>();
}

const ::std::string&
Demo::PrinterPrx::ice_staticId()
{
    return Demo::Printer::ice_staticId();
}

#else // C++98 mapping

namespace
{

const ::std::string iceC_Demo_Printer_printString_name = "printString";

}
::IceProxy::Ice::Object* ::IceProxy::Demo::upCast(::IceProxy::Demo::Printer* p) { return p; }

void
::IceProxy::Demo::_readProxy(::Ice::InputStream* istr, ::IceInternal::ProxyHandle< ::IceProxy::Demo::Printer>& v)
{
    ::Ice::ObjectPrx proxy;
    istr->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Demo::Printer;
        v->_copyFrom(proxy);
    }
}

::Ice::AsyncResultPtr
IceProxy::Demo::Printer::_iceI_begin_printString(const ::std::string& iceP_s, const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_Demo_Printer_printString_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_Demo_Printer_printString_name, ::Ice::Normal, context);
        ::Ice::OutputStream* ostr = result->startWriteParams(::Ice::DefaultFormat);
        ostr->write(iceP_s);
        result->endWriteParams();
        result->invoke(iceC_Demo_Printer_printString_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

void
IceProxy::Demo::Printer::end_printString(const ::Ice::AsyncResultPtr& result)
{
    _end(result, iceC_Demo_Printer_printString_name);
}

::IceProxy::Ice::Object*
IceProxy::Demo::Printer::_newInstance() const
{
    return new Printer;
}

const ::std::string&
IceProxy::Demo::Printer::ice_staticId()
{
    return ::Demo::Printer::ice_staticId();
}

Demo::Printer::~Printer()
{
}

::Ice::Object* Demo::upCast(::Demo::Printer* p) { return p; }


namespace
{
const ::std::string iceC_Demo_Printer_ids[2] =
{
    "::Demo::Printer",
    "::Ice::Object"
};

}

bool
Demo::Printer::ice_isA(const ::std::string& s, const ::Ice::Current&) const
{
    return ::std::binary_search(iceC_Demo_Printer_ids, iceC_Demo_Printer_ids + 2, s);
}

::std::vector< ::std::string>
Demo::Printer::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&iceC_Demo_Printer_ids[0], &iceC_Demo_Printer_ids[2]);
}

const ::std::string&
Demo::Printer::ice_id(const ::Ice::Current&) const
{
    return ice_staticId();
}

const ::std::string&
Demo::Printer::ice_staticId()
{
#ifdef ICE_HAS_THREAD_SAFE_LOCAL_STATIC
    static const ::std::string typeId = "::Demo::Printer";
    return typeId;
#else
    return iceC_Demo_Printer_ids[0];
#endif
}

bool
Demo::Printer::_iceD_printString(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    ::Ice::InputStream* istr = inS.startReadParams();
    ::std::string iceP_s;
    istr->read(iceP_s);
    inS.endReadParams();
    this->printString(iceP_s, current);
    inS.writeEmptyParams();
    return true;
}

namespace
{
const ::std::string iceC_Demo_Printer_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "printString"
};

}

bool
Demo::Printer::_iceDispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair<const ::std::string*, const ::std::string*> r = ::std::equal_range(iceC_Demo_Printer_all, iceC_Demo_Printer_all + 5, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - iceC_Demo_Printer_all)
    {
        case 0:
        {
            return _iceD_ice_id(in, current);
        }
        case 1:
        {
            return _iceD_ice_ids(in, current);
        }
        case 2:
        {
            return _iceD_ice_isA(in, current);
        }
        case 3:
        {
            return _iceD_ice_ping(in, current);
        }
        case 4:
        {
            return _iceD_printString(in, current);
        }
        default:
        {
            assert(false);
            throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
        }
    }
}

void
Demo::Printer::_iceWriteImpl(::Ice::OutputStream* ostr) const
{
    ostr->startSlice(ice_staticId(), -1, true);
    Ice::StreamWriter< ::Demo::Printer, ::Ice::OutputStream>::write(ostr, *this);
    ostr->endSlice();
}

void
Demo::Printer::_iceReadImpl(::Ice::InputStream* istr)
{
    istr->startSlice();
    Ice::StreamReader< ::Demo::Printer, ::Ice::InputStream>::read(istr, *this);
    istr->endSlice();
}

void
Demo::_icePatchObjectPtr(PrinterPtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = ::Demo::PrinterPtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(::Demo::Printer::ice_staticId(), v);
    }
}

namespace Ice
{
}

#endif