<form action="" method="post">
MAY TINH BO TUI :<align="center"/></br>
So A :<input type ="text" name="soa" placeholder="so a" value=""/></br></br>
So B :<input type ="text" name="sob" placeholder="so b" value=""/></br></br>
Lua chon :</br>
<input type ="radio" name="cong"> Cong Hai So</br></br>
<input type ="radio" name="tru"> Hieu Hai So</br></br>
<input type ="radio" name="nhan"> Nhan Hai So</br></br>
<input type ="radio" name="chia"> Chia Hai So</br></br>
<input type="reset" name="nhaplai" value="nhap lai"/>
<input type="submit" name="tinh" value="tinh"/>
</form>
<?php

	if($_SERVER["REQUEST_METHOD"]=="POST")
	{
		if(!empty($_POST["soa"])&&!empty($_POST["sob"]))
		{
		$a=$_POST["soa"];
		$b=$_POST["sob"];
			if(isset($_POST["cong"]))
			{
				echo"</br>"."Tong hai so ";
				$cong=$a+$b;
				echo"</br>"."$a + $b=$cong";
			}
			if(isset($_POST["tru"]))
			{
				echo"</br>"."Hieu hai so ";
				$hieu=$a-$b;
				echo"</br>"."$a - $b=$hieu";
			}
			if(isset($_POST["nhan"]))
			{
				echo"</br>"."Tich hai so ";
				$nhan=$a*$b;
				echo"</br>"."$a x $b=$nhan";
			}
			if(isset($_POST["chia"]))
			{
				echo"</br>"."Chia hai so ";
				$chia=$a/$b;
				echo"</br>"."$a / $b=$chia";
			}
		}
		else{echo"</br>"."thong tin nhap chua day du";}
	}
?>