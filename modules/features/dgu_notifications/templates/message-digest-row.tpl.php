<?php
print "\n-------------------------------------------------------------\n";
print 'Message from ' . format_date($message->timestamp, 'medium') . "\n";
print "-------------------------------------------------------------\n";
print implode($rows);