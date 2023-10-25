# This is the simple implementation of CFS
# The purpose is to simulate how tasks are perform under multi-task theory
1. CFS

# Sample output
# Time quantum system 1 --- Owner:  process job_1 is calling with virtual time is 1
# Time quantum system 2 --- Owner:  process job_2 is calling with virtual time is 2
# Time quantum system 3 --- Owner:  process job_2 is calling with virtual time is 1
# Time quantum system 4 --- Owner:  process job_3 is calling with virtual time is 4
# Time quantum system 1 --- Owner:  process job_4 is calling with virtual time is 5
# Time quantum system 2 --- Owner:  process job_6 is calling with virtual time is 5
# Time quantum system 3 --- Owner:  process job_3 is calling with virtual time is 3
# Time quantum system 4 --- Owner:  process job_4 is calling with virtual time is 4
# Time quantum system 1 --- Owner:  process job_6 is calling with virtual time is 4
# Time quantum system 2 --- Owner:  process job_3 is calling with virtual time is 2
# Time quantum system 3 --- Owner:  process job_5 is calling with virtual time is 7
# Time quantum system 4 --- Owner:  process job_4 is calling with virtual time is 3
# Time quantum system 1 --- Owner:  process job_6 is calling with virtual time is 3
# Time quantum system 2 --- Owner:  process job_3 is calling with virtual time is 1
# Time quantum system 3 --- Owner:  process job_5 is calling with virtual time is 6
# Time quantum system 4 --- Owner:  process job_4 is calling with virtual time is 2
# Time quantum system 1 --- Owner:  process job_6 is calling with virtual time is 2
# Time quantum system 2 --- Owner:  process job_5 is calling with virtual time is 5
# Time quantum system 3 --- Owner:  process job_4 is calling with virtual time is 1
# Time quantum system 4 --- Owner:  process job_6 is calling with virtual time is 1
# Time quantum system 1 --- Owner:  process job_5 is calling with virtual time is 4
# Time quantum system 2 --- Owner:  process job_5 is calling with virtual time is 3
# Time quantum system 3 --- Owner:  process job_5 is calling with virtual time is 2
# Time quantum system 4 --- Owner:  process job_5 is calling with virtual time is 1
