<?php

echo shell_exec('sh ./KOD/program '.escapeshellarg($_POST['funkcija']).' '.escapeshellarg($_POST['iteracije']).' '.escapeshellarg($_POST['ponavljanja']).'  '.escapeshellarg($_POST['n']).' 
	'escapeshellarg(.$_POST['omega']).' '.escapeshellarg($_POST['ro_p']).' '.escapeshellarg($_POST['ro_g']).' '.escapeshellarg($_POST['m']).' '.escapeshellarg($_POST['e']).'');

?>
