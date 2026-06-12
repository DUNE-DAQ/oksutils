/*
 * DUNE DAQ modification notice:
 * This file has been modified from the original ATLAS oks_utils source for the DUNE DAQ project.
 * Fork baseline commit: c2e7dfc7 (2022-03-30).
 * Renamed since fork: yes (from oks/ral.h to include/oksutils/oks/ral.hpp).
 */

#ifndef OKS_RAL_H
#define OKS_RAL_H

#include <memory>
#include <vector>
#include <string>

#include "boost/date_time/local_time/local_time.hpp"

  // DEFINEs to switch on / off verbose output 

#define VerboseMsg1( MSG ) { if(verbose_level > 0) { std::cout << MSG << std::endl; } }
#define VerboseMsg2( MSG ) { if(verbose_level > 1) { std::cout << MSG << std::endl; } }
#define VerboseMsg3( MSG ) { if(verbose_level > 2) { std::cout << MSG << std::endl; } }
#define VerboseMsg4( MSG ) { if(verbose_level > 3) { std::cout << MSG << std::endl; } }
#define VerboseMsg5( MSG ) { if(verbose_level > 4) { std::cout << MSG << std::endl; } }


namespace coral {
  class ISessionProxy;
  class ConnectionService;
  class AttributeList;
}

#include "oks/class.hpp"
#include "oks/object.hpp"

namespace oks {

 namespace ral {

      /**
       * \brief Start coral session.
       *
       *  Loads all required CORAL services, establishes connection with RDBMS and starts new transaction.
       *
       *  The parameters are:
       *  \param connect_string  connection to be used with this session (parameters are in the authentication.xml file)
       *  \param mode            pass coral::Update for write access or coral::ReadOnly for read-only access
       *  \param connection      out parameter returning pointer to CORAL connection object
       *  \param verbose_level   level of verbose output (0 - none, 1 - normal, 2 - extended, 3 - debug, ...)
       */

  coral::ISessionProxy * start_coral_session(const std::string& connect_string, int mode, std::unique_ptr<coral::ConnectionService>& connection, int verbose_level);


      /**
       * \brief Get HEAD schema version number.
       *
       *  The function returns schema with maximum version number for given release.
       *
       *  The parameters are:
       *  \param session         pointer on CORAL session
       *  \param schema          working schema
       *  \param release         name of the release, for which take the schema (if null, use current release)
       *  \param verbose_level   level of verbose output (0 - none, 1 - normal, 2 - extended, 3 - debug, ...)
       *  \param dx              optional string to shift verbose output; to be used for alignment
       *
       *  \return Return head version.
       */

    int get_head_schema_version(
            coral::ISessionProxy * session,
            const std::string& schema,
            const char * release = 0,
            int verbose_level = 1,
	    const char * dx = "");


      /**
       * \brief Get maximum schema version number.
       *
       *  The function returns maximum schema version number to be used to choose free version number.
       *
       *  The parameters are:
       *  \param session         pointer on CORAL session
       *  \param schema          working schema
       *  \param verbose_level   level of verbose output (0 - none, 1 - normal, 2 - extended, 3 - debug, ...)
       *  \param dx              optional string to shift verbose output; to be used for alignment
       *
       *  \return Return head version.
       */

    int get_max_schema_version(
            coral::ISessionProxy * session,
            const std::string& schema,
            int verbose_level = 1,
            const char * dx = "");


      /**
       * \brief Get schema versions for given release.
       *
       *  The function returns all existing schema version numbers for given release.
       *
       *  The parameters are:
       *  \param session         pointer on CORAL session
       *  \param schema          working schema
       *  \param release         name of the release, for which take the schema (if null, use current release)
       *  \param verbose_level   level of verbose output (0 - none, 1 - normal, 2 - extended, 3 - debug, ...)
       *  \param dx              optional string to shift verbose output; to be used for alignment
       *
       *  \return Return schema versions in descent order.
       */

    std::vector<int> get_schema_versions(
            coral::ISessionProxy * session,
            const std::string& schema,
            const char * release = 0,
            int verbose_level = 1,
	    const char * dx = "");


      /**
       * \brief Get data version by tag.
       *
       *  The function returns data version for given tag.
       *
       *  The parameters are:
       *  \param session         pointer on CORAL session
       *  \param schema          working schema
       *  \param tag             tag of the data; if empty, get HEAD version
       *  \param schema_version  returned schema version
       *  \param data_version    returned data version
       *  \param release         name of release to get HEAD version (if null, use current release)
       *  \param verbose_level   level of verbose output (0 - none, 1 - normal, 2 - extended, 3 - debug, ...)
       *  \param dx              optional string to shift verbose output; to be used for alignment
       */

    void get_data_version(
            coral::ISessionProxy * session,
            const std::string& schema,
            const std::string& tag,
            int& schema_version,
            int& data_version,
            const char * release = 0,
            int verbose_level = 1,
	    const char * dx = "");


      /**
       * \brief Get schema by version number.
       *
       *  The function reads oks classes from relational database and defines them in the oks kernel.
       *
       *  The parameters are:
       *  \param kernel          oks kernel used to define oks classes
       *  \param schema          working schema
       *  \param session         pointer on CORAL session
       *  \param version         existing schema version
       *  \param read_methods    do not read description of methods (e.g. when only data are needed)
       *  \param verbose_level   level of verbose output (0 - none, 1 - normal, 2 - extended, 3 - debug, ...)
       */

    void get_schema(
            OksKernel& kernel,
            coral::ISessionProxy * session,
            const std::string& schema,
            int version,
	    bool read_methods,
            int verbose_level);


      /**
       * \brief Get data by version numbers.
       *
       *  The function reads oks objects from relational database and defines them in the oks kernel.
       *
       *  The parameters are:
       *  \param kernel          oks kernel used to define oks classes
       *  \param session         pointer on CORAL session
       *  \param schema          working schema
       *  \param schema_version  existing schema version
       *  \param data_version    existing data version
       *  \param verbose_level   level of verbose output (0 - none, 1 - normal, 2 - extended, 3 - debug, ...)
       *  \param pattern         if defined, the read classes must match the pattern
       *
       *  \return Return total number of rows read from relational tables to get the data.
       */

    unsigned long get_data(
            OksKernel& kernel,
            coral::ISessionProxy * session,
            const std::string& schema,
            int schema_version,
            int data_version,
            int verbose_level,
            const OksClass::Map * pattern = 0);


      /**
       * \brief Create new schema or add classesto existing schema.
       *
       *  The function creates new schema or updates existing schema in the relational database
       *  and stores there oks classes.
       *
       *  The parameters are:
       *  \param classes         oks classes to be stored in the new schema
       *  \param session         pointer on CORAL session
       *  \param schema          working schema
       *  \param schema_version  if >0 - new schema version; if 0, create new head version incrementing max defined version; if <0, add classes to existing schema = MOD(schema_version)
       *  \param description     description for new schema
       *  \param verbose_level   level of verbose output (0 - none, 1 - normal, 2 - extended, 3 - debug, ...)
       */

    void put_schema(
            const OksClass::Map& classes,
            coral::ISessionProxy * session,
            const std::string& schema,
            int schema_version,
            const std::string& description,
            int verbose_level);


      /**
       *  \brief Structure to describe number of changes when new version is created.
       *
       *  If m_use_base is set to true, no changes are necessary
       *  (schema_version and data_version parameters of put_data()
       *  return versions to used to access stored data). 
       */

    struct InsertedDataDetails {
      long m_insertedOksObjectRowsThis;
      long m_insertedOksObjectRowsBase;
      long m_insertedOksDataRelRowsThis;
      long m_insertedOksDataRelRowsBase;
      long m_insertedOksDataValRowsThis;
      long m_insertedOksDataValRowsBase;
      bool m_use_base;

      InsertedDataDetails() :
        m_insertedOksObjectRowsThis  (0),
	m_insertedOksObjectRowsBase  (0),
	m_insertedOksDataRelRowsThis (0),
	m_insertedOksDataRelRowsBase (0),
	m_insertedOksDataValRowsThis (0),
	m_insertedOksDataValRowsBase (0),
	m_use_base (false) { ; }
    };


      /**
       * \brief Create new data.
       *
       *  The function creates new data in the relational database and stores there oks objects.
       *
       *  The parameters are:
       *  \param kernel          kernel containing oks objects to be stored
       *  \param objects         if defined, then only put such objects; otherwise put ALL objects
       *  \param session         pointer on CORAL session
       *  \param schema          working schema
       *  \param schema_version  existing schema version; if 0, use head schema version
       *  \param data_version    new data version; if 0, create new head version incrementing max defined data version for given schema
       *  \param base_version    if < 0, create new full version; if > 0, use given version as base for incremental versioning; if = 0, use head version as base version
       *  \param description     description for new data
       *  \param inc_threshold   if it is above 0, then defines incremental version threshold size (data are not copied from tempral tables on exceed)
       *  \param verbose_level   level of verbose output (0 - none, 1 - normal, 2 - extended, 3 - debug, ...)
       *
       *  \return Return number of relational tables rows to store the data; if it is negative, the new version is the same as the base version. The schema_version and data_version parameters return versions to used to access stored data. 
       */

   InsertedDataDetails put_data(
            OksKernel& kernel,
            OksObject::FSet * objects,
            coral::ISessionProxy * session,
            const std::string& schema,
            int& schema_version,
            int& data_version,
            int base_version,
            const std::string& description,
            long inc_threshold,
            int verbose_level);


      /**
       * \brief Tag data version.
       *
       *  The function sets tag to existing schema and data versions.
       *
       *  The parameters are:
       *  \param session         pointer on CORAL session
       *  \param schema          working schema
       *  \param schema_version  existing schema version
       *  \param data_version    existing data version
       *  \param tag             unique tag
       *  \param verbose_level   level of verbose output (0 - none, 1 - normal, 2 - extended, 3 - debug, ...)
       */

   void tag_data(
            coral::ISessionProxy * session,
            const std::string& schema,
            int schema_version,
            int data_version,
            const std::string& tag,
            int verbose_level);


      /**
       * \brief Store information about used data.
       *
       *  The function is TDAQ specific. It stores information about OKS data used
       *  for data-taking runs referencing configuration by partition name, run number and time.
       *
       *  The parameters are:
       *  \param session         pointer on CORAL session
       *  \param schema_version  existing schema version
       *  \param schema          working schema
       *  \param data_version    existing data version
       *  \param partition_name  name of the TDAQ partition          
       *  \param run_number      number of the TDAQ data-taking run        
       *  \param verbose_level   level of verbose output (0 - none, 1 - normal, 2 - extended, 3 - debug, ...)
       */

   void create_archive_record(
            coral::ISessionProxy * session,
            const std::string& schema,
            int schema_version,
            int data_version,
            const std::string& partition_name,
            int run_number,
            int verbose_level);


   void get_time_host_user(
            const coral::AttributeList& data,
	    std::string& time,
	    std::string& host,
	    std::string& user,
	    boost::local_time::time_zone_ptr tz_ptr, 
	    const char * prefix = 0);



 } /* close namespace 'ral' */

} /* close namespace 'oks' */

#endif
