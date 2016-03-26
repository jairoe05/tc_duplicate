// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: report_service.proto

#ifndef PROTOBUF_report_5fservice_2eproto__INCLUDED
#define PROTOBUF_report_5fservice_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "attribute_types.pb.h"
#include "entity_types.pb.h"
#include "rpc_types.pb.h"
#include "ServiceBase.h"
#include "MessageBuffer.h"
#include <functional>
#include <type_traits>
// @@protoc_insertion_point(includes)

namespace bgs {
namespace protocol {
namespace report {
namespace v1 {

// Internal implementation detail -- do not call these.
void TC_SHARED_API protobuf_AddDesc_report_5fservice_2eproto();
void protobuf_AssignDesc_report_5fservice_2eproto();
void protobuf_ShutdownFile_report_5fservice_2eproto();

class Report;
class SendReportRequest;

// ===================================================================

class TC_SHARED_API Report : public ::google::protobuf::Message {
 public:
  Report();
  virtual ~Report();

  Report(const Report& from);

  inline Report& operator=(const Report& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Report& default_instance();

  void Swap(Report* other);

  // implements Message ----------------------------------------------

  Report* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Report& from);
  void MergeFrom(const Report& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string report_type = 1;
  inline bool has_report_type() const;
  inline void clear_report_type();
  static const int kReportTypeFieldNumber = 1;
  inline const ::std::string& report_type() const;
  inline void set_report_type(const ::std::string& value);
  inline void set_report_type(const char* value);
  inline void set_report_type(const char* value, size_t size);
  inline ::std::string* mutable_report_type();
  inline ::std::string* release_report_type();
  inline void set_allocated_report_type(::std::string* report_type);

  // repeated .bgs.protocol.Attribute attribute = 2;
  inline int attribute_size() const;
  inline void clear_attribute();
  static const int kAttributeFieldNumber = 2;
  inline const ::bgs::protocol::Attribute& attribute(int index) const;
  inline ::bgs::protocol::Attribute* mutable_attribute(int index);
  inline ::bgs::protocol::Attribute* add_attribute();
  inline const ::google::protobuf::RepeatedPtrField< ::bgs::protocol::Attribute >&
      attribute() const;
  inline ::google::protobuf::RepeatedPtrField< ::bgs::protocol::Attribute >*
      mutable_attribute();

  // optional int32 report_qos = 3 [default = 0];
  inline bool has_report_qos() const;
  inline void clear_report_qos();
  static const int kReportQosFieldNumber = 3;
  inline ::google::protobuf::int32 report_qos() const;
  inline void set_report_qos(::google::protobuf::int32 value);

  // optional .bgs.protocol.EntityId reporting_account = 4;
  inline bool has_reporting_account() const;
  inline void clear_reporting_account();
  static const int kReportingAccountFieldNumber = 4;
  inline const ::bgs::protocol::EntityId& reporting_account() const;
  inline ::bgs::protocol::EntityId* mutable_reporting_account();
  inline ::bgs::protocol::EntityId* release_reporting_account();
  inline void set_allocated_reporting_account(::bgs::protocol::EntityId* reporting_account);

  // optional .bgs.protocol.EntityId reporting_game_account = 5;
  inline bool has_reporting_game_account() const;
  inline void clear_reporting_game_account();
  static const int kReportingGameAccountFieldNumber = 5;
  inline const ::bgs::protocol::EntityId& reporting_game_account() const;
  inline ::bgs::protocol::EntityId* mutable_reporting_game_account();
  inline ::bgs::protocol::EntityId* release_reporting_game_account();
  inline void set_allocated_reporting_game_account(::bgs::protocol::EntityId* reporting_game_account);

  // optional fixed64 report_timestamp = 6;
  inline bool has_report_timestamp() const;
  inline void clear_report_timestamp();
  static const int kReportTimestampFieldNumber = 6;
  inline ::google::protobuf::uint64 report_timestamp() const;
  inline void set_report_timestamp(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:bgs.protocol.report.v1.Report)
 private:
  inline void set_has_report_type();
  inline void clear_has_report_type();
  inline void set_has_report_qos();
  inline void clear_has_report_qos();
  inline void set_has_reporting_account();
  inline void clear_has_reporting_account();
  inline void set_has_reporting_game_account();
  inline void clear_has_reporting_game_account();
  inline void set_has_report_timestamp();
  inline void clear_has_report_timestamp();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* report_type_;
  ::google::protobuf::RepeatedPtrField< ::bgs::protocol::Attribute > attribute_;
  ::bgs::protocol::EntityId* reporting_account_;
  ::bgs::protocol::EntityId* reporting_game_account_;
  ::google::protobuf::uint64 report_timestamp_;
  ::google::protobuf::int32 report_qos_;
  friend void TC_SHARED_API protobuf_AddDesc_report_5fservice_2eproto();
  friend void protobuf_AssignDesc_report_5fservice_2eproto();
  friend void protobuf_ShutdownFile_report_5fservice_2eproto();

  void InitAsDefaultInstance();
  static Report* default_instance_;
};
// -------------------------------------------------------------------

class TC_SHARED_API SendReportRequest : public ::google::protobuf::Message {
 public:
  SendReportRequest();
  virtual ~SendReportRequest();

  SendReportRequest(const SendReportRequest& from);

  inline SendReportRequest& operator=(const SendReportRequest& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SendReportRequest& default_instance();

  void Swap(SendReportRequest* other);

  // implements Message ----------------------------------------------

  SendReportRequest* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SendReportRequest& from);
  void MergeFrom(const SendReportRequest& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required .bgs.protocol.report.v1.Report report = 1;
  inline bool has_report() const;
  inline void clear_report();
  static const int kReportFieldNumber = 1;
  inline const ::bgs::protocol::report::v1::Report& report() const;
  inline ::bgs::protocol::report::v1::Report* mutable_report();
  inline ::bgs::protocol::report::v1::Report* release_report();
  inline void set_allocated_report(::bgs::protocol::report::v1::Report* report);

  // @@protoc_insertion_point(class_scope:bgs.protocol.report.v1.SendReportRequest)
 private:
  inline void set_has_report();
  inline void clear_has_report();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::bgs::protocol::report::v1::Report* report_;
  friend void TC_SHARED_API protobuf_AddDesc_report_5fservice_2eproto();
  friend void protobuf_AssignDesc_report_5fservice_2eproto();
  friend void protobuf_ShutdownFile_report_5fservice_2eproto();

  void InitAsDefaultInstance();
  static SendReportRequest* default_instance_;
};
// ===================================================================

class TC_SHARED_API ReportService : public ServiceBase
{
 public:

  template<typename HashSelector>
  explicit ReportService(HashSelector) : service_hash_(HashSelector::Result::value) { }

  typedef std::integral_constant<uint32, 0x7CAF61C9u> OriginalHash;
  typedef std::integral_constant<uint32, 0x724F5F47u> NameHash;

  static google::protobuf::ServiceDescriptor const* descriptor();

  // client methods --------------------------------------------------

  void SendReport(::bgs::protocol::report::v1::SendReportRequest const* request, std::function<void(::bgs::protocol::NoData const*)> responseCallback);
  // server methods --------------------------------------------------

  void CallServerMethod(uint32 token, uint32 methodId, MessageBuffer buffer) override final;

 protected:
  virtual uint32 HandleSendReport(::bgs::protocol::report::v1::SendReportRequest const* request, ::bgs::protocol::NoData* response);

 private:
  uint32 service_hash_;

  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(ReportService);
};

// ===================================================================


// ===================================================================

// Report

// required string report_type = 1;
inline bool Report::has_report_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Report::set_has_report_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Report::clear_has_report_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Report::clear_report_type() {
  if (report_type_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    report_type_->clear();
  }
  clear_has_report_type();
}
inline const ::std::string& Report::report_type() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.report.v1.Report.report_type)
  return *report_type_;
}
inline void Report::set_report_type(const ::std::string& value) {
  set_has_report_type();
  if (report_type_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    report_type_ = new ::std::string;
  }
  report_type_->assign(value);
  // @@protoc_insertion_point(field_set:bgs.protocol.report.v1.Report.report_type)
}
inline void Report::set_report_type(const char* value) {
  set_has_report_type();
  if (report_type_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    report_type_ = new ::std::string;
  }
  report_type_->assign(value);
  // @@protoc_insertion_point(field_set_char:bgs.protocol.report.v1.Report.report_type)
}
inline void Report::set_report_type(const char* value, size_t size) {
  set_has_report_type();
  if (report_type_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    report_type_ = new ::std::string;
  }
  report_type_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:bgs.protocol.report.v1.Report.report_type)
}
inline ::std::string* Report::mutable_report_type() {
  set_has_report_type();
  if (report_type_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    report_type_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:bgs.protocol.report.v1.Report.report_type)
  return report_type_;
}
inline ::std::string* Report::release_report_type() {
  clear_has_report_type();
  if (report_type_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = report_type_;
    report_type_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Report::set_allocated_report_type(::std::string* report_type) {
  if (report_type_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete report_type_;
  }
  if (report_type) {
    set_has_report_type();
    report_type_ = report_type;
  } else {
    clear_has_report_type();
    report_type_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:bgs.protocol.report.v1.Report.report_type)
}

// repeated .bgs.protocol.Attribute attribute = 2;
inline int Report::attribute_size() const {
  return attribute_.size();
}
inline void Report::clear_attribute() {
  attribute_.Clear();
}
inline const ::bgs::protocol::Attribute& Report::attribute(int index) const {
  // @@protoc_insertion_point(field_get:bgs.protocol.report.v1.Report.attribute)
  return attribute_.Get(index);
}
inline ::bgs::protocol::Attribute* Report::mutable_attribute(int index) {
  // @@protoc_insertion_point(field_mutable:bgs.protocol.report.v1.Report.attribute)
  return attribute_.Mutable(index);
}
inline ::bgs::protocol::Attribute* Report::add_attribute() {
  // @@protoc_insertion_point(field_add:bgs.protocol.report.v1.Report.attribute)
  return attribute_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::bgs::protocol::Attribute >&
Report::attribute() const {
  // @@protoc_insertion_point(field_list:bgs.protocol.report.v1.Report.attribute)
  return attribute_;
}
inline ::google::protobuf::RepeatedPtrField< ::bgs::protocol::Attribute >*
Report::mutable_attribute() {
  // @@protoc_insertion_point(field_mutable_list:bgs.protocol.report.v1.Report.attribute)
  return &attribute_;
}

// optional int32 report_qos = 3 [default = 0];
inline bool Report::has_report_qos() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Report::set_has_report_qos() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Report::clear_has_report_qos() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Report::clear_report_qos() {
  report_qos_ = 0;
  clear_has_report_qos();
}
inline ::google::protobuf::int32 Report::report_qos() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.report.v1.Report.report_qos)
  return report_qos_;
}
inline void Report::set_report_qos(::google::protobuf::int32 value) {
  set_has_report_qos();
  report_qos_ = value;
  // @@protoc_insertion_point(field_set:bgs.protocol.report.v1.Report.report_qos)
}

// optional .bgs.protocol.EntityId reporting_account = 4;
inline bool Report::has_reporting_account() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Report::set_has_reporting_account() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Report::clear_has_reporting_account() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Report::clear_reporting_account() {
  if (reporting_account_ != NULL) reporting_account_->::bgs::protocol::EntityId::Clear();
  clear_has_reporting_account();
}
inline const ::bgs::protocol::EntityId& Report::reporting_account() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.report.v1.Report.reporting_account)
  return reporting_account_ != NULL ? *reporting_account_ : *default_instance_->reporting_account_;
}
inline ::bgs::protocol::EntityId* Report::mutable_reporting_account() {
  set_has_reporting_account();
  if (reporting_account_ == NULL) reporting_account_ = new ::bgs::protocol::EntityId;
  // @@protoc_insertion_point(field_mutable:bgs.protocol.report.v1.Report.reporting_account)
  return reporting_account_;
}
inline ::bgs::protocol::EntityId* Report::release_reporting_account() {
  clear_has_reporting_account();
  ::bgs::protocol::EntityId* temp = reporting_account_;
  reporting_account_ = NULL;
  return temp;
}
inline void Report::set_allocated_reporting_account(::bgs::protocol::EntityId* reporting_account) {
  delete reporting_account_;
  reporting_account_ = reporting_account;
  if (reporting_account) {
    set_has_reporting_account();
  } else {
    clear_has_reporting_account();
  }
  // @@protoc_insertion_point(field_set_allocated:bgs.protocol.report.v1.Report.reporting_account)
}

// optional .bgs.protocol.EntityId reporting_game_account = 5;
inline bool Report::has_reporting_game_account() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Report::set_has_reporting_game_account() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Report::clear_has_reporting_game_account() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Report::clear_reporting_game_account() {
  if (reporting_game_account_ != NULL) reporting_game_account_->::bgs::protocol::EntityId::Clear();
  clear_has_reporting_game_account();
}
inline const ::bgs::protocol::EntityId& Report::reporting_game_account() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.report.v1.Report.reporting_game_account)
  return reporting_game_account_ != NULL ? *reporting_game_account_ : *default_instance_->reporting_game_account_;
}
inline ::bgs::protocol::EntityId* Report::mutable_reporting_game_account() {
  set_has_reporting_game_account();
  if (reporting_game_account_ == NULL) reporting_game_account_ = new ::bgs::protocol::EntityId;
  // @@protoc_insertion_point(field_mutable:bgs.protocol.report.v1.Report.reporting_game_account)
  return reporting_game_account_;
}
inline ::bgs::protocol::EntityId* Report::release_reporting_game_account() {
  clear_has_reporting_game_account();
  ::bgs::protocol::EntityId* temp = reporting_game_account_;
  reporting_game_account_ = NULL;
  return temp;
}
inline void Report::set_allocated_reporting_game_account(::bgs::protocol::EntityId* reporting_game_account) {
  delete reporting_game_account_;
  reporting_game_account_ = reporting_game_account;
  if (reporting_game_account) {
    set_has_reporting_game_account();
  } else {
    clear_has_reporting_game_account();
  }
  // @@protoc_insertion_point(field_set_allocated:bgs.protocol.report.v1.Report.reporting_game_account)
}

// optional fixed64 report_timestamp = 6;
inline bool Report::has_report_timestamp() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void Report::set_has_report_timestamp() {
  _has_bits_[0] |= 0x00000020u;
}
inline void Report::clear_has_report_timestamp() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void Report::clear_report_timestamp() {
  report_timestamp_ = GOOGLE_ULONGLONG(0);
  clear_has_report_timestamp();
}
inline ::google::protobuf::uint64 Report::report_timestamp() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.report.v1.Report.report_timestamp)
  return report_timestamp_;
}
inline void Report::set_report_timestamp(::google::protobuf::uint64 value) {
  set_has_report_timestamp();
  report_timestamp_ = value;
  // @@protoc_insertion_point(field_set:bgs.protocol.report.v1.Report.report_timestamp)
}

// -------------------------------------------------------------------

// SendReportRequest

// required .bgs.protocol.report.v1.Report report = 1;
inline bool SendReportRequest::has_report() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SendReportRequest::set_has_report() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SendReportRequest::clear_has_report() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SendReportRequest::clear_report() {
  if (report_ != NULL) report_->::bgs::protocol::report::v1::Report::Clear();
  clear_has_report();
}
inline const ::bgs::protocol::report::v1::Report& SendReportRequest::report() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.report.v1.SendReportRequest.report)
  return report_ != NULL ? *report_ : *default_instance_->report_;
}
inline ::bgs::protocol::report::v1::Report* SendReportRequest::mutable_report() {
  set_has_report();
  if (report_ == NULL) report_ = new ::bgs::protocol::report::v1::Report;
  // @@protoc_insertion_point(field_mutable:bgs.protocol.report.v1.SendReportRequest.report)
  return report_;
}
inline ::bgs::protocol::report::v1::Report* SendReportRequest::release_report() {
  clear_has_report();
  ::bgs::protocol::report::v1::Report* temp = report_;
  report_ = NULL;
  return temp;
}
inline void SendReportRequest::set_allocated_report(::bgs::protocol::report::v1::Report* report) {
  delete report_;
  report_ = report;
  if (report) {
    set_has_report();
  } else {
    clear_has_report();
  }
  // @@protoc_insertion_point(field_set_allocated:bgs.protocol.report.v1.SendReportRequest.report)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace report
}  // namespace protocol
}  // namespace bgs

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_report_5fservice_2eproto__INCLUDED
