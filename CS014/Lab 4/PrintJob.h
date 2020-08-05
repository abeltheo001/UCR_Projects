#ifndef __PRINTJOB_H
#define __PRINTJOB_H

class PrintJob {
private:
  int priority;
  int jobNumber;
  int numPages;

public:
  PrintJob ( int, int, int);
  int getPriority ( );
  int getJobNumber ( );
  int getPages ( );
};
#endif