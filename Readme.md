
IUSM-MSC
=========

This repository contains the main applications used in the IUSM Medical 
Student Council.

Each application is located in the respective folder. A short description of 
each application is listed below.

Committee Selection
----

The committee selection tool is used to determine the 'optimal' placement of 
applicants to a committee. The tool uses a ranked list supplied by both the 
committee and the applicant. Each committee ranks their top applicants (with
1 being the most preferred applicant) and each applicant ranks their top 
committee. The program then computes the optimal order of applicants for each
committee and outputs the result. The quota for each committee must be 
provided in the committee CSV file. The number of alternates for each 
committee can alse be adjusted

A test data file for both the committee rank list and applicant rank list is
provided.

#### Compilation and Execution
Compile using:
```bash
g++ committeeSelection.cpp -o committeeSelection
```
Run using:
```bash
./committeeSelection committee.csv applicant.csv 2
```
Where 'committee.csv' is the committee CSV file, 'applicant.csv' is the 
applicant CSV file, and '2' is the number of alternates.

## Application PDF
The ApplicationPDF tool creates a PDF application for each applicant in a 
CSV file.