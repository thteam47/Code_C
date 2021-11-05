<!DOCTYPE html>
<html>
	<body>
		<form acion="" method="post">
		<table border=0  width=200 height=200>
		<tr align=center>Dang Ky </tr>
		<tr>
			
			<td>Ma sv </td><td><input type="text" name="masv" placeholder="ma sv" value="" </td> 
		</tr>
		<tr>
			<td>hoten </td><td><input type="text" name="hoten" placeholder="ho ten" value="" </td>
		</tr>
		<tr>
			<td>ngay sinh </td><td><input type="text" name="ngaysinh" placeholder="ngay sinh" value="" </td>
		</tr>
		<tr>
			<td>gioitinh </td><td><input type ="radio" name="nam">nam <input type ="radio" name="nu">nu</td>
		</tr>
		<tr>
			<td>noi sinh </td><td><input type="text" name="noisinh" placeholder="noi sinh" value="" </td>
		</tr>
		<tr>
			<td>lop</td><td><input type="text" name="lop" placeholder="lop" value="" </td>
		</tr>
		<tr>
			<td></td><td><input type ="reset" name="nhaplai" value="nhap lai"> <input type ="submit" name="Dangky" value="Dang ky"></td>
		</tr>
		
</html>
<?php
	if($_SERVER["REQUEST_METHOD"]=="POST")
	{
		if(!empty($_POST["masv"])&&!empty($_POST["hoten"])&&!empty($_POST["ngaysinh"])&&!empty($_POST["noisinh"])&&!empty($_POST["lop"])&&((isset($_POST["nam"])||isset($_POST["nu"]))))
		{
			echo"<table border=1 width=400 height=200>";
				echo"<tr>";
					$ma=$_POST["masv"];
					echo"<td align=center>Ma Sv</td><td align=center> $ma</td>";
				echo"</tr>";
				echo"<tr>";
					$ht=$_POST["hoten"];
					echo"<td align=center>Ho Ten</td><td align=center>$ht</td>";
				echo"</tr>";
				echo"<tr>";
					$ns=$_POST["ngaysinh"];
					echo"<td align=center>Ngay Sinh</td><td align=center>$ns</td>";
				echo"<tr>";
				echo"</tr>";
				echo"<td align=center>Gioi Tinh</td>";
					if(isset($_POST["nam"])){
					$nam='nam';
					echo"<td align=center>$nam</td>";}

					else if(isset($_POST["nu"])){
					$nu='nu';
					echo"<td align=center>$nu</td>";}
				echo"</tr>";
				echo"<tr>";
					$nois=$_POST["masv"];
					echo"<td align=center>Noi Sinh</td><td align=center> $nois</td>";
				echo"</tr>";
				echo"<tr>";
					$lop=$_POST["masv"];
					echo"<td align=center>Lop</td><td align=center>$lop</td>";
				echo"</tr>";
			echo"</table>";
		}
		else
		{echo"</br>"."thong tin nhap chua day du";}
	}
?>