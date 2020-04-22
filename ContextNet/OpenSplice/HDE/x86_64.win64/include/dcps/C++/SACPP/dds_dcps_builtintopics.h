//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: dds_dcps_builtintopics.h
//  Source: ../../../../etc/idl/dds_dcps_builtintopics.idl
//  Generated: Tue Apr 15 14:15:28 2014
//  OpenSplice V6.4.140407OSS
//  
//******************************************************************
#ifndef _DDS_DCPS_BUILTINTOPICS_H_
#define _DDS_DCPS_BUILTINTOPICS_H_

#include "sacpp_mapping.h"
#include "sacpp_DDS_DCPS.h"
#include "sacpp_if.h"
#include "dds_builtinTopics.h"


namespace DDS
{
   struct Time_t;
   struct EntityFactoryQosPolicy;
   struct WriterDataLifecycleQosPolicy;
   struct InvalidSampleVisibilityQosPolicy;
   struct ReaderDataLifecycleQosPolicy;
   struct SubscriptionKeyQosPolicy;
   struct ReaderLifespanQosPolicy;
   struct ShareQosPolicy;
   struct SchedulingClassQosPolicy;
   struct SchedulingPriorityQosPolicy;
   struct SchedulingQosPolicy;
   struct ViewKeyQosPolicy;
   struct DataReaderViewQos;
   struct DomainParticipantFactoryQos;
   struct DomainParticipantQos;
   struct TopicQos;
   struct DataWriterQos;
   struct PublisherQos;
   struct DataReaderQos;
   struct SubscriberQos;

   struct SACPP_API Time_t
   {
         Long sec;
         ULong nanosec;
   };

   typedef DDS_DCPSStruct_var < Time_t> Time_t_var;
   typedef Time_t&Time_t_out;

   struct SACPP_API EntityFactoryQosPolicy
   {
         Boolean autoenable_created_entities;
   };

   typedef DDS_DCPSStruct_var < EntityFactoryQosPolicy> EntityFactoryQosPolicy_var;
   typedef EntityFactoryQosPolicy&EntityFactoryQosPolicy_out;

   struct SACPP_API WriterDataLifecycleQosPolicy
   {
         Boolean autodispose_unregistered_instances;
         Duration_t autopurge_suspended_samples_delay;
         Duration_t autounregister_instance_delay;
   };

   typedef DDS_DCPSStruct_var < WriterDataLifecycleQosPolicy> WriterDataLifecycleQosPolicy_var;
   typedef WriterDataLifecycleQosPolicy&WriterDataLifecycleQosPolicy_out;
   enum InvalidSampleVisibilityQosPolicyKind
   {
      NO_INVALID_SAMPLES,
      MINIMUM_INVALID_SAMPLES,
      ALL_INVALID_SAMPLES
   };

   struct SACPP_API InvalidSampleVisibilityQosPolicy
   {
         InvalidSampleVisibilityQosPolicyKind kind;
   };

   typedef DDS_DCPSStruct_var < InvalidSampleVisibilityQosPolicy> InvalidSampleVisibilityQosPolicy_var;
   typedef InvalidSampleVisibilityQosPolicy&InvalidSampleVisibilityQosPolicy_out;

   struct SACPP_API ReaderDataLifecycleQosPolicy
   {
         Duration_t autopurge_nowriter_samples_delay;
         Duration_t autopurge_disposed_samples_delay;
         Boolean enable_invalid_samples;
         InvalidSampleVisibilityQosPolicy invalid_sample_visibility;
   };

   typedef DDS_DCPSStruct_var < ReaderDataLifecycleQosPolicy> ReaderDataLifecycleQosPolicy_var;
   typedef ReaderDataLifecycleQosPolicy&ReaderDataLifecycleQosPolicy_out;

   struct SACPP_API SubscriptionKeyQosPolicy
   {
         Boolean use_key_list;
         StringSeq key_list;
   };

   typedef DDS_DCPSStruct_var < SubscriptionKeyQosPolicy> SubscriptionKeyQosPolicy_var;
   typedef DDS_DCPSStruct_out < SubscriptionKeyQosPolicy> SubscriptionKeyQosPolicy_out;

   struct SACPP_API ReaderLifespanQosPolicy
   {
         Boolean use_lifespan;
         Duration_t duration;
   };

   typedef DDS_DCPSStruct_var < ReaderLifespanQosPolicy> ReaderLifespanQosPolicy_var;
   typedef ReaderLifespanQosPolicy&ReaderLifespanQosPolicy_out;

   struct SACPP_API ShareQosPolicy
   {
         String_mgr name;
         Boolean enable;
   };

   typedef DDS_DCPSStruct_var < ShareQosPolicy> ShareQosPolicy_var;
   typedef DDS_DCPSStruct_out < ShareQosPolicy> ShareQosPolicy_out;
   enum SchedulingClassQosPolicyKind
   {
      SCHEDULE_DEFAULT,
      SCHEDULE_TIMESHARING,
      SCHEDULE_REALTIME
   };

   struct SACPP_API SchedulingClassQosPolicy
   {
         SchedulingClassQosPolicyKind kind;
   };

   typedef DDS_DCPSStruct_var < SchedulingClassQosPolicy> SchedulingClassQosPolicy_var;
   typedef SchedulingClassQosPolicy&SchedulingClassQosPolicy_out;
   enum SchedulingPriorityQosPolicyKind
   {
      PRIORITY_RELATIVE,
      PRIORITY_ABSOLUTE
   };

   struct SACPP_API SchedulingPriorityQosPolicy
   {
         SchedulingPriorityQosPolicyKind kind;
   };

   typedef DDS_DCPSStruct_var < SchedulingPriorityQosPolicy> SchedulingPriorityQosPolicy_var;
   typedef SchedulingPriorityQosPolicy&SchedulingPriorityQosPolicy_out;

   struct SACPP_API SchedulingQosPolicy
   {
         SchedulingClassQosPolicy scheduling_class;
         SchedulingPriorityQosPolicy scheduling_priority_kind;
         Long scheduling_priority;
   };

   typedef DDS_DCPSStruct_var < SchedulingQosPolicy> SchedulingQosPolicy_var;
   typedef SchedulingQosPolicy&SchedulingQosPolicy_out;

   struct SACPP_API ViewKeyQosPolicy
   {
         Boolean use_key_list;
         StringSeq key_list;
   };

   typedef DDS_DCPSStruct_var < ViewKeyQosPolicy> ViewKeyQosPolicy_var;
   typedef DDS_DCPSStruct_out < ViewKeyQosPolicy> ViewKeyQosPolicy_out;

   struct SACPP_API DataReaderViewQos
   {
         ViewKeyQosPolicy view_keys;
   };

   typedef DDS_DCPSStruct_var < DataReaderViewQos> DataReaderViewQos_var;
   typedef DDS_DCPSStruct_out < DataReaderViewQos> DataReaderViewQos_out;

   struct SACPP_API DomainParticipantFactoryQos
   {
         EntityFactoryQosPolicy entity_factory;
   };

   typedef DDS_DCPSStruct_var < DomainParticipantFactoryQos> DomainParticipantFactoryQos_var;
   typedef DomainParticipantFactoryQos&DomainParticipantFactoryQos_out;

   struct SACPP_API DomainParticipantQos
   {
         UserDataQosPolicy user_data;
         EntityFactoryQosPolicy entity_factory;
         SchedulingQosPolicy watchdog_scheduling;
         SchedulingQosPolicy listener_scheduling;
   };

   typedef DDS_DCPSStruct_var < DomainParticipantQos> DomainParticipantQos_var;
   typedef DDS_DCPSStruct_out < DomainParticipantQos> DomainParticipantQos_out;

   struct SACPP_API TopicQos
   {
         TopicDataQosPolicy topic_data;
         DurabilityQosPolicy durability;
         DurabilityServiceQosPolicy durability_service;
         DeadlineQosPolicy deadline;
         LatencyBudgetQosPolicy latency_budget;
         LivelinessQosPolicy liveliness;
         ReliabilityQosPolicy reliability;
         DestinationOrderQosPolicy destination_order;
         HistoryQosPolicy history;
         ResourceLimitsQosPolicy resource_limits;
         TransportPriorityQosPolicy transport_priority;
         LifespanQosPolicy lifespan;
         OwnershipQosPolicy ownership;
   };

   typedef DDS_DCPSStruct_var < TopicQos> TopicQos_var;
   typedef DDS_DCPSStruct_out < TopicQos> TopicQos_out;

   struct SACPP_API DataWriterQos
   {
         DurabilityQosPolicy durability;
         DeadlineQosPolicy deadline;
         LatencyBudgetQosPolicy latency_budget;
         LivelinessQosPolicy liveliness;
         ReliabilityQosPolicy reliability;
         DestinationOrderQosPolicy destination_order;
         HistoryQosPolicy history;
         ResourceLimitsQosPolicy resource_limits;
         TransportPriorityQosPolicy transport_priority;
         LifespanQosPolicy lifespan;
         UserDataQosPolicy user_data;
         OwnershipQosPolicy ownership;
         OwnershipStrengthQosPolicy ownership_strength;
         WriterDataLifecycleQosPolicy writer_data_lifecycle;
   };

   typedef DDS_DCPSStruct_var < DataWriterQos> DataWriterQos_var;
   typedef DDS_DCPSStruct_out < DataWriterQos> DataWriterQos_out;

   struct SACPP_API PublisherQos
   {
         PresentationQosPolicy presentation;
         PartitionQosPolicy partition;
         GroupDataQosPolicy group_data;
         EntityFactoryQosPolicy entity_factory;
   };

   typedef DDS_DCPSStruct_var < PublisherQos> PublisherQos_var;
   typedef DDS_DCPSStruct_out < PublisherQos> PublisherQos_out;

   struct SACPP_API DataReaderQos
   {
         DurabilityQosPolicy durability;
         DeadlineQosPolicy deadline;
         LatencyBudgetQosPolicy latency_budget;
         LivelinessQosPolicy liveliness;
         ReliabilityQosPolicy reliability;
         DestinationOrderQosPolicy destination_order;
         HistoryQosPolicy history;
         ResourceLimitsQosPolicy resource_limits;
         UserDataQosPolicy user_data;
         OwnershipQosPolicy ownership;
         TimeBasedFilterQosPolicy time_based_filter;
         ReaderDataLifecycleQosPolicy reader_data_lifecycle;
         SubscriptionKeyQosPolicy subscription_keys;
         ReaderLifespanQosPolicy reader_lifespan;
         ShareQosPolicy share;
   };

   typedef DDS_DCPSStruct_var < DataReaderQos> DataReaderQos_var;
   typedef DDS_DCPSStruct_out < DataReaderQos> DataReaderQos_out;

   struct SACPP_API SubscriberQos
   {
         PresentationQosPolicy presentation;
         PartitionQosPolicy partition;
         GroupDataQosPolicy group_data;
         EntityFactoryQosPolicy entity_factory;
         ShareQosPolicy share;
   };

   typedef DDS_DCPSStruct_var < SubscriberQos> SubscriberQos_var;
   typedef DDS_DCPSStruct_out < SubscriberQos> SubscriberQos_out;
}




#endif 