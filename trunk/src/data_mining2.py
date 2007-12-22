#!/usr/bin/python

""" Luncher, able to lunch different stuff with different parameters.
"""

__author__ = 'pierre.ruyssen@gmail.com (Pierre Ruyssen)'

import re
import sys
import commands
import os

def write_result(file_name, result):
  f = open(file_name, 'w')
  for line in result:
    f.write(line)
  f.close()

DEFAULT_OUTPUT = "output.csv" #output file

# list of files to execute, with the different
# combinaisons of arguments
EXECS = ['./vns', './recuit']
results = ['' for i in range(len(EXECS))]

ports = ['SIMPLE.txt', 'FTSE.txt', 'HG.txt', 'NKI.txt', 'SetP.txt', 'DAX.txt']
portsFE = ['SIMPLE_FE.txt', 'FTSE_FE.txt', 'HG_FE.txt', 'NKI_FE.txt', 'SetP_FE.txt', 'DAX_FE.txt']

regFE = re.compile("(?P<rho>\d*[\.|,]\d+)\s+(?P<risk>\d*[\.|,]\d+)")
regOUTPUT = re.compile("(?P<risk>\d*[\.|,]\d+)")

for i in range(len(ports)):
  f = open('../benchmark/'+portsFE[i], 'r')
  for line in f:
    res = regFE.search(line)
    if res:
      for j in range(len(EXECS)):
        command = "%s ../benchmark/%s %s" % (EXECS[j], ports[i], res.groupdict()["rho"])
        print command
        output = commands.getoutput(command)
        if regOUTPUT.search(output): 
          results[j] += "%s %s\n" % (res.groupdict()["rho"] ,output)
          print results[j]
        else: print output

  write_result('../benchmark/'+portsFE[i]+'_vns', results[0])
  write_result('../benchmark/'+portsFE[i]+'_recuit', results[1])
  

          




