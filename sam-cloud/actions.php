<?php
$m = new MongoClient("mongodb://localhost:27017"); // connect
$db = $m->selectDB("sam");
?>