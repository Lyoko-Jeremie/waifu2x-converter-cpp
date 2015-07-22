#ifndef TIMEGUARD_H
#define TIMEGUARD_H

// 必须在外面包含  好奇怪
#include <iostream>
#include <sstream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

/// To Switch Use OpenCV-Tick OR ctime-clock
//#define TIME_CLOCK
#define CV_TICK



namespace TGuard {

#ifdef CV_TICK
    #include <opencv2/core/core.hpp>
    #include <opencv2/highgui/highgui.hpp>
#endif /* CV_TICK */


namespace TimerFunction {




    #ifdef TIME_CLOCK
    typedef long ttype;
    #endif // TIME_CLOCK
    #ifdef CV_TICK
    typedef double ttype;
    #endif // CV_TICK

    inline ttype getNowTime()
    {
        #ifdef TIME_CLOCK
        return clock();
        #endif // TIME_CLOCK
        #ifdef CV_TICK
        return static_cast<double>( cv::getTickCount() ) * static_cast<double>(1000) / static_cast<double>( cv::getTickFrequency() );
        #endif // CV_TICK
    }

    inline std::string FormatTime( ttype timemsd )
    {
        long long int timems = timemsd;
        int ms = timems % 1000;
        timems /= 1000;
        int s = timems % 60;
        timems /= 60;
        int m = timems % 60;
        timems /= 60;
        int h = timems % 24;
        timems /= 24;
        int d = timems;
        std::stringstream ss;
        ss << d << " day " << h << " hour " << m << " minute " << s << " second " << ms << " ms";
        return ss.str();
    }

    inline std::string getTime()
    {
        time_t timet = time( nullptr );
        tm date = *localtime(&timet);
        std::stringstream ss;
        ss << (date.tm_year + 1900) << "-" << date.tm_mon << "-" << date.tm_mday << "\t" << date.tm_hour << ":" << date.tm_min << ":" << date.tm_sec ;
        return ss.str();
    }

}

// 计时器
class TimeGuard
{
    public:

        inline TimeGuard( bool AreOut, bool AreSave, std::string TimeName):
            Out(AreOut),
            Save(AreSave),
            TimeNow(TimerFunction::getNowTime()),
            Tname(TimeName),
            Date(TimerFunction::getTime())
        {
            Start(NONAME);
        }

        inline TimeGuard( bool AreOut, bool AreSave, std::string TimeName, std::string Name):
            Out(AreOut),
            Save(AreSave),
            TimeNow(TimerFunction::getNowTime()),
            Tname(TimeName),
            Date(TimerFunction::getTime())
        {
            Start(Name);
        }

        ~TimeGuard()
        {
            Out = false;
            Stop();
            if (Save)
            {
                std::fstream fout( std::string("TimeGuard.log") , std::fstream::out | std::fstream::app );
                fout << "\n\n" << std::endl;
                fout << "============================================" << std::endl;
                fout << "Now Time : " << TimerFunction::getTime() << std::endl;
                fout << Data.str() ;
                fout << "============================================" << std::endl;
                fout.close();
            }
        }

        inline TimerFunction::ttype Start()
        {
            return Start(NONAME);
        }

        inline TimerFunction::ttype Start( std::string Name)
        {
            this->Name = Name;
            Available = true;
            TimeLast = TimerFunction::getNowTime();
            return TimeLast;
        }

        inline TimerFunction::ttype Stop()
        {
            if (Available)
            {
                TimeNow = TimerFunction::getNowTime();
                TimerFunction::ttype timems = TimeNow - TimeLast;
                Available = false;
                std::stringstream ss;
                ss << Tname << " --- " << Name << " ===\t" << timems << " ms.\n" << TimerFunction::FormatTime(timems) << "." << std::endl;
                if (Out)
                {
                    std::cout << std::endl << ss.str();
                }
                if (Save)
                {
                    Data << ss.str();
                }
                TimeLast = 0;
                TimeNow = 0;
                Name = NONAME;
                return timems;
            }else{
                if (Out)
                {
                    std::cout << "No Count." << std::endl;
                }
                return 0;
            }
        }

        inline TimerFunction::ttype Next()
        {
            TimerFunction::ttype time = Stop();
            Start();
            return time;
        }

        inline TimerFunction::ttype Next( std::string name)
        {
            TimerFunction::ttype time = Stop();
            Start(name);
            return time;
        }

        inline TimerFunction::ttype Next( std::string name, bool lout)
        {
            bool t = this->Out;
            this->Out = lout;
            TimerFunction::ttype time = this->Next(name);
            this->Out = t;
            return time;
        }

    protected:
        bool Out;
        bool Save;
        bool Available;
        std::string Name;
        TimerFunction::ttype TimeLast;
        TimerFunction::ttype TimeNow;
        std::string const NONAME = "No Name";
        std::string Tname;
        std::ostringstream Data;
        std::string const Date;
    private:
};

}

#endif // TIMEGUARD_H
