Solutions Considered
 1. String Matching:
    Directly checking if the log line starts with the given date.
    With string match we can go for a sequential log parsing in a simple and efficient manner.
    This even works for structured log files.
 2. Regular Expressions:
    Use regex patterns to extract log entries matching a specific date format.
    Can match different log formats with more flexibility
     Can extract specific details (e.g., timestamps, error types, etc.)
 3. Binary Search on Sorted Logs:
    If logs were sorted by date, we could use binary search to quickly find the first log entry of a given date.
    Instead of reading the whole file line by line,
    Find the first occurrence of YYYY-MM-DD using binary search,
    Extract all lines for that date until the next date appears
    

Final Solution Summary:
    we are using string matching because it reads the file only once  with no regex  or parsing needed and even works well for structured logs  with a timestamp mentioned on it.

    
Steps to Run:
    1. Compile the C++ Code
        g++ extract_logs.cpp -o extract_logs
    2. Run the Executable
        ./extract_logs 2024-01-31
    3. Check the Output
