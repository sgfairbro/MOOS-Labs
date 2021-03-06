// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: acomms_example.proto

#ifndef PROTOBUF_acomms_5fexample_2eproto__INCLUDED
#define PROTOBUF_acomms_5fexample_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "goby/acomms/protobuf/dccl_option_extensions.pb.h"
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_acomms_5fexample_2eproto();
void protobuf_AssignDesc_acomms_5fexample_2eproto();
void protobuf_ShutdownFile_acomms_5fexample_2eproto();

class AcommsExampleMessage1;
class AcommsExampleMessage2;

enum Sender {
  HENRIK = 1,
  MIKERB = 2,
  TES = 3,
  AYAARI = 4,
  ARTHURA = 5,
  SDANESH = 6,
  EMF43 = 7
};
bool Sender_IsValid(int value);
const Sender Sender_MIN = HENRIK;
const Sender Sender_MAX = EMF43;
const int Sender_ARRAYSIZE = Sender_MAX + 1;

const ::google::protobuf::EnumDescriptor* Sender_descriptor();
inline const ::std::string& Sender_Name(Sender value) {
  return ::google::protobuf::internal::NameOfEnum(
    Sender_descriptor(), value);
}
inline bool Sender_Parse(
    const ::std::string& name, Sender* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Sender>(
    Sender_descriptor(), name, value);
}
// ===================================================================

class AcommsExampleMessage1 : public ::google::protobuf::Message {
 public:
  AcommsExampleMessage1();
  virtual ~AcommsExampleMessage1();

  AcommsExampleMessage1(const AcommsExampleMessage1& from);

  inline AcommsExampleMessage1& operator=(const AcommsExampleMessage1& from) {
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
  static const AcommsExampleMessage1& default_instance();

  void Swap(AcommsExampleMessage1* other);

  // implements Message ----------------------------------------------

  AcommsExampleMessage1* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const AcommsExampleMessage1& from);
  void MergeFrom(const AcommsExampleMessage1& from);
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

  // required double time = 1;
  inline bool has_time() const;
  inline void clear_time();
  static const int kTimeFieldNumber = 1;
  inline double time() const;
  inline void set_time(double value);

  // required uint32 index = 2;
  inline bool has_index() const;
  inline void clear_index();
  static const int kIndexFieldNumber = 2;
  inline ::google::protobuf::uint32 index() const;
  inline void set_index(::google::protobuf::uint32 value);

  // required int32 random = 3;
  inline bool has_random() const;
  inline void clear_random();
  static const int kRandomFieldNumber = 3;
  inline ::google::protobuf::int32 random() const;
  inline void set_random(::google::protobuf::int32 value);

  // required .Sender sender = 4;
  inline bool has_sender() const;
  inline void clear_sender();
  static const int kSenderFieldNumber = 4;
  inline ::Sender sender() const;
  inline void set_sender(::Sender value);

  // @@protoc_insertion_point(class_scope:AcommsExampleMessage1)
 private:
  inline void set_has_time();
  inline void clear_has_time();
  inline void set_has_index();
  inline void clear_has_index();
  inline void set_has_random();
  inline void clear_has_random();
  inline void set_has_sender();
  inline void clear_has_sender();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  double time_;
  ::google::protobuf::uint32 index_;
  ::google::protobuf::int32 random_;
  int sender_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_acomms_5fexample_2eproto();
  friend void protobuf_AssignDesc_acomms_5fexample_2eproto();
  friend void protobuf_ShutdownFile_acomms_5fexample_2eproto();

  void InitAsDefaultInstance();
  static AcommsExampleMessage1* default_instance_;
};
// -------------------------------------------------------------------

class AcommsExampleMessage2 : public ::google::protobuf::Message {
 public:
  AcommsExampleMessage2();
  virtual ~AcommsExampleMessage2();

  AcommsExampleMessage2(const AcommsExampleMessage2& from);

  inline AcommsExampleMessage2& operator=(const AcommsExampleMessage2& from) {
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
  static const AcommsExampleMessage2& default_instance();

  void Swap(AcommsExampleMessage2* other);

  // implements Message ----------------------------------------------

  AcommsExampleMessage2* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const AcommsExampleMessage2& from);
  void MergeFrom(const AcommsExampleMessage2& from);
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

  // required double time = 1;
  inline bool has_time() const;
  inline void clear_time();
  static const int kTimeFieldNumber = 1;
  inline double time() const;
  inline void set_time(double value);

  // required uint32 index = 2;
  inline bool has_index() const;
  inline void clear_index();
  static const int kIndexFieldNumber = 2;
  inline ::google::protobuf::uint32 index() const;
  inline void set_index(::google::protobuf::uint32 value);

  // required bool toggle = 3;
  inline bool has_toggle() const;
  inline void clear_toggle();
  static const int kToggleFieldNumber = 3;
  inline bool toggle() const;
  inline void set_toggle(bool value);

  // required .Sender sender = 4;
  inline bool has_sender() const;
  inline void clear_sender();
  static const int kSenderFieldNumber = 4;
  inline ::Sender sender() const;
  inline void set_sender(::Sender value);

  // @@protoc_insertion_point(class_scope:AcommsExampleMessage2)
 private:
  inline void set_has_time();
  inline void clear_has_time();
  inline void set_has_index();
  inline void clear_has_index();
  inline void set_has_toggle();
  inline void clear_has_toggle();
  inline void set_has_sender();
  inline void clear_has_sender();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  double time_;
  ::google::protobuf::uint32 index_;
  bool toggle_;
  int sender_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_acomms_5fexample_2eproto();
  friend void protobuf_AssignDesc_acomms_5fexample_2eproto();
  friend void protobuf_ShutdownFile_acomms_5fexample_2eproto();

  void InitAsDefaultInstance();
  static AcommsExampleMessage2* default_instance_;
};
// ===================================================================


// ===================================================================

// AcommsExampleMessage1

// required double time = 1;
inline bool AcommsExampleMessage1::has_time() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void AcommsExampleMessage1::set_has_time() {
  _has_bits_[0] |= 0x00000001u;
}
inline void AcommsExampleMessage1::clear_has_time() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void AcommsExampleMessage1::clear_time() {
  time_ = 0;
  clear_has_time();
}
inline double AcommsExampleMessage1::time() const {
  return time_;
}
inline void AcommsExampleMessage1::set_time(double value) {
  set_has_time();
  time_ = value;
}

// required uint32 index = 2;
inline bool AcommsExampleMessage1::has_index() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void AcommsExampleMessage1::set_has_index() {
  _has_bits_[0] |= 0x00000002u;
}
inline void AcommsExampleMessage1::clear_has_index() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void AcommsExampleMessage1::clear_index() {
  index_ = 0u;
  clear_has_index();
}
inline ::google::protobuf::uint32 AcommsExampleMessage1::index() const {
  return index_;
}
inline void AcommsExampleMessage1::set_index(::google::protobuf::uint32 value) {
  set_has_index();
  index_ = value;
}

// required int32 random = 3;
inline bool AcommsExampleMessage1::has_random() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void AcommsExampleMessage1::set_has_random() {
  _has_bits_[0] |= 0x00000004u;
}
inline void AcommsExampleMessage1::clear_has_random() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void AcommsExampleMessage1::clear_random() {
  random_ = 0;
  clear_has_random();
}
inline ::google::protobuf::int32 AcommsExampleMessage1::random() const {
  return random_;
}
inline void AcommsExampleMessage1::set_random(::google::protobuf::int32 value) {
  set_has_random();
  random_ = value;
}

// required .Sender sender = 4;
inline bool AcommsExampleMessage1::has_sender() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void AcommsExampleMessage1::set_has_sender() {
  _has_bits_[0] |= 0x00000008u;
}
inline void AcommsExampleMessage1::clear_has_sender() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void AcommsExampleMessage1::clear_sender() {
  sender_ = 1;
  clear_has_sender();
}
inline ::Sender AcommsExampleMessage1::sender() const {
  return static_cast< ::Sender >(sender_);
}
inline void AcommsExampleMessage1::set_sender(::Sender value) {
  assert(::Sender_IsValid(value));
  set_has_sender();
  sender_ = value;
}

// -------------------------------------------------------------------

// AcommsExampleMessage2

// required double time = 1;
inline bool AcommsExampleMessage2::has_time() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void AcommsExampleMessage2::set_has_time() {
  _has_bits_[0] |= 0x00000001u;
}
inline void AcommsExampleMessage2::clear_has_time() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void AcommsExampleMessage2::clear_time() {
  time_ = 0;
  clear_has_time();
}
inline double AcommsExampleMessage2::time() const {
  return time_;
}
inline void AcommsExampleMessage2::set_time(double value) {
  set_has_time();
  time_ = value;
}

// required uint32 index = 2;
inline bool AcommsExampleMessage2::has_index() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void AcommsExampleMessage2::set_has_index() {
  _has_bits_[0] |= 0x00000002u;
}
inline void AcommsExampleMessage2::clear_has_index() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void AcommsExampleMessage2::clear_index() {
  index_ = 0u;
  clear_has_index();
}
inline ::google::protobuf::uint32 AcommsExampleMessage2::index() const {
  return index_;
}
inline void AcommsExampleMessage2::set_index(::google::protobuf::uint32 value) {
  set_has_index();
  index_ = value;
}

// required bool toggle = 3;
inline bool AcommsExampleMessage2::has_toggle() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void AcommsExampleMessage2::set_has_toggle() {
  _has_bits_[0] |= 0x00000004u;
}
inline void AcommsExampleMessage2::clear_has_toggle() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void AcommsExampleMessage2::clear_toggle() {
  toggle_ = false;
  clear_has_toggle();
}
inline bool AcommsExampleMessage2::toggle() const {
  return toggle_;
}
inline void AcommsExampleMessage2::set_toggle(bool value) {
  set_has_toggle();
  toggle_ = value;
}

// required .Sender sender = 4;
inline bool AcommsExampleMessage2::has_sender() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void AcommsExampleMessage2::set_has_sender() {
  _has_bits_[0] |= 0x00000008u;
}
inline void AcommsExampleMessage2::clear_has_sender() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void AcommsExampleMessage2::clear_sender() {
  sender_ = 1;
  clear_has_sender();
}
inline ::Sender AcommsExampleMessage2::sender() const {
  return static_cast< ::Sender >(sender_);
}
inline void AcommsExampleMessage2::set_sender(::Sender value) {
  assert(::Sender_IsValid(value));
  set_has_sender();
  sender_ = value;
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Sender>() {
  return ::Sender_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_acomms_5fexample_2eproto__INCLUDED
