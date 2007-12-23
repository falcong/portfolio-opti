#!/usr/bin/python

""" Luncher, able to lunch different stuff with different parameters.
"""

__author__ = 'pierre.ruyssen@gmail.com (Pierre Ruyssen)'

import re
import sys
import commands
import os
import StringIO
from time import sleep
from select import *
from subprocess import *
from signal import SIGTERM

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

ports = ['SetP.txt', 'DAX.txt', 'NKI.txt', 'SIMPLE.txt', 'FTSE.txt'] #, 'HG.txt']
portsFE = ['SetP_FE.txt', 'DAX_FE.txt', 'NKI_FE.txt', 'SIMPLE_FE.txt', 'FTSE_FE.txt']#, 'HG_FE.txt']

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
        for k in range(10):
          try:
            #output = commands.getoutput(command)

            pop = Popen(command, shell=True, stdout=PIPE)

            for t in range(10*k+2):
              sleep(1)
              if pop.poll() != None: break
            if(pop.poll()==None) :
              try:
                commands.getoutput("killall vns")
                commands.getoutput("killall recuit")
              except:
                pass
              raise KeyboardInterrupt()

            output = pop.stdout.read()
            #output = StringIO.StringIO(pop.stdout)
            
            res2 = regOUTPUT.search(output)
            if res2: 
              s = "%s %s\n" % (res.groupdict()["rho"] ,res2.groupdict()["risk"])
              results[j] += s
              print s
            else: raise KeyboardInterrupt()
            break
          except KeyboardInterrupt:
            print "Attemp %d" % (k)

  write_result('../benchmark/log/'+portsFE[i]+'_vns.log', results[0])
  write_result('../benchmark/log/'+portsFE[i]+'_recuit.log', results[1])
  

          




