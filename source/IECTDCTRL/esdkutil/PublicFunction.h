#pragma once

class CPublicFunction
{
public:
  CPublicFunction(void);
  virtual ~CPublicFunction(void);
public:
  static CString UTF2UNICODE(const std::string str);//UTF-8ת����UNICODE
  static std::string UNICODE2UTF(const CString cstr);//UNICODEת����UTF-8
};
