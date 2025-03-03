#include <string>
#include <vector>
#include <cstdint>

#ifndef PRIME_ENTRY_HEADER
#define PRIME_ENTRY_HEADER

class PrimeEntry
{
public:
  PrimeEntry();
  ~PrimeEntry() {};
  void setOriginalVal(unsigned long int v) {m_orig=v;};
  void setReceivedIndex(unsigned int v)    {m_received_index=v;};
  void setCalculatedIndex(unsigned int v)  {m_calculated_index=v;};
  void setDone(bool v)                     {m_done=v;};
  void setRTime(double v)                  {m_rtime=v;};
  void setCTime(double v)                  {m_ctime=v;};
  
  uint64_t getOriginVal()                  {return m_orig;};

  bool done()                              {return(m_done);};
  
  bool factor(unsigned long int max_steps);
  
  std::string  getReport();

  uint64_t getFactor()                     {return m_factors.back();};
  void setFactor(uint64_t v)               {m_factors.push_back(v);};
  bool started()                           {return m_factors.size()>0;};
  double m_part_way;
  bool m_started;

protected:
  uint64_t      m_start_index;
  uint64_t      m_orig;
  bool          m_done;
  unsigned int  m_received_index;
  unsigned int  m_calculated_index;
  double        m_rtime;
  double        m_ctime;
  std::vector<uint64_t> m_factors;
};
#endif