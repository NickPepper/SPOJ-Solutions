        IDENTIFICATION DIVISION.
        PROGRAM-ID. SAMPLE.
 
        ENVIRONMENT DIVISION.
 
        DATA DIVISION.
        WORKING-STORAGE SECTION.
        77 n PIC Z9 .
 
        PROCEDURE DIVISION.
                ACCEPT n
                PERFORM UNTIL n = 42
                        DISPLAY n
                        ACCEPT n
                END-PERFORM.
                STOP RUN.
 
