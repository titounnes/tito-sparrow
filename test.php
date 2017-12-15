<?php
use Sparrow\Lib\Sparrow;

$db = new Sparrow();
echo "\n";
echo $db->from('user')->select()->sql();
echo "\n";
echo $db->from('user')
    ->where('id', 123)
    ->where('name', 'bob')
    ->select()
    ->sql();
echo "\n";
