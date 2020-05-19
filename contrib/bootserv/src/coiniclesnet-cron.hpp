#ifndef BOOTSERV_COINICLESNET_CRON_HPP
#define BOOTSERV_COINICLESNET_CRON_HPP

#include "handler.hpp"

namespace coiniclesnet
{
  namespace bootserv
  {
    struct CronHandler final : public Handler
    {
      CronHandler(std::ostream& o);
      ~CronHandler();

      int
      Exec(const Config& conf) override;

      int
      ReportError(const char* err) override;
    };

  }  // namespace bootserv
}  // namespace coiniclesnet

#endif
