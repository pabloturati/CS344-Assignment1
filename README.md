# CS344-Assignment1
CS344-Assignment1 Movie List reader in C
Author: Pablo Turati - turatip@oregonstate.edu
Licence: MIT. 
Refer to `LICENSE` for details.

## Project Description

Application that reads data from a CSV file, provides user with the following functionality:

1. Movies release in the specified year.
2. Highest rated movie for each year.
3. Movies and their year of release for a specific language.

## Compile instructions

### Option 1.  Using compile script

This application includes a bash script to build and deploy the runner (compileApp.sh).  To use it, make sure that this file (compileApp.sh) has execution persmissions by running:

`$ chmod +x compileApp.sh`

Once it is ready, you may execute the compile instructions by running from the project root:

`$ ./compileApp.sh`

This will generate a `movies` exectable file as output. Refer to the next section on how to run the application and pass parameters.

### Option 2.  Individual commands

Refer to the contents of `compileApp.sh` for a detailed command list on how to manually compile using command line.

## Run procedure

Once the application executable has been created `movies`. It can be run as follows:

`$ ./movies <filename.csv>`

An example where the file name is: `movies_sample_1.csv` would be:
`$ ./movies movies_sample_1.csv`

Where movies_sample_file must be a comma-separated file (.csv) with the following structure and application data type interpretation:

 - Movie Title :: string
 - Year :: integer number
 - Languages :: string 
 - Rating Value :: floating point number

 ## Additional resources

 Link to the repository is available at [here](https://github.com/pabloturati/CS344-Assignment1).  However, due to this being an Oregon State University assignment, it will remain private and public access will become available after April, 2021.