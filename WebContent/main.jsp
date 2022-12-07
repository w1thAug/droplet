<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>SHIFT</title>

<script src="http://cdnjs.cloudflare.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/exif-js"></script>
<script>
	var ext_type = 'png,jpg,jpeg'.toUpperCase();
	//확장자체크
    function fn_checkExt(file) {
       
        var fileName = file.name;
        var file_ext = fileName.substring(fileName.lastIndexOf('.') + 1).toUpperCase();
        if (ext_type != '' && ext_type.indexOf(file_ext) == -1) {
            return false
        } else {
            return true
        }
    }
	
    function getMetaData() {
        var fileTag = $('[name=file1]');
        if (!fileTag.val()) {
            alert("파일을 업로드하세요!");
            return
        }
        var file = fileTag[0].files[0];
        if (fn_checkExt(file) == false) {
            alert(ext_type + '의 확장자만 가능합니다.');
            return
        }
        getMetaDataParse(file)
    }

	//메타데이터 파싱
    function getMetaDataParse(t) {
        $('.map_wrap').hide();
        EXIF.getData(t, function () {
                var t, I, F, T, l, E;
                EXIF.pretty(this)
                    ?
                    (
						t = "",
                            I = EXIF.getTag(this, "DateTimeOriginal"),
                            (l = EXIF.getTag(this, "GPSLongitude")) ?
                                (
                                    E = EXIF.getTag(this, "GPSLongitudeRef"), 
                                        T = EXIF.getTag(this, "GPSLatitude"),
                                        t += " 위도 : " + (F = "S" == EXIF.getTag(this, "GPSLatitudeRef") ? -1 * T[0] + (-60 * T[1] + -1 * T[2]) / 3600 : T[0] + (60 * T[1] + T[2]) / 3600) + "<br>",
                                        t += " 경도 : " + (T = "W" == E ? -1 * l[0] + (-60 * l[1] + -1 * l[2]) / 3600 : l[0] + (60 * l[1] + l[2]) / 3600) + "<br>",
                                        l = (E = I.split(" "))[0].replace(":", "").replace(":", ""),
                                        E = (E = E[1].split(":"))[0] + "" + E[1]
                                ) : t += "<span style='color:red'>위치 정보를 추출할 수 없습니다.</span><br>",
						t += "", $("#text").html(t))
	                :
	                $("#text").html("위치 정보를 추출할 수 없습니다.")
            	}
        );
        var e = new FileReader;
        e.readAsDataURL(t), e.onload = function () {
            var t;
            e.result ? (t = "<img id='imagsss' src='" + e.result + "' width='350px'/>", $("#imgdiv").html(t)) : $("#imgdiv").html("Error!");
        }
    }
</script>

<style>

	#containernDivs{
		width : 100%;
	}

    .nDivs_i {
        width: 90%;
        background: #fff;
        padding-top: 20px;
    }

    .nDivs_i .input_inform {
        width: 50%;

    }

    .nDivs_i .input_inform input {
        width: 71%;
        border: none;
        border-bottom: 1px solid #ccc;

        margin-top: 10px;
        padding: 10px 15px
    }
	
	.button { width : 80%; }
    .button .nDivs a {
        display: block;
        width: 70%;
        margin-top: 4%;
        padding: 11px 0;
        text-align: center;
        border-radius: 5px;
        border: 1px solid #3784e0;
        color: #fff;
        font-weight: 700;
        text-decoration: none;
    }

    .button .nDivs a:first-child {
        border: none;
        background: #000;
        color: #fff;
		width : 50%;
    }
    .nDivs_wrap2 {
        width: 80%;

    }

</style>

</head>
<body>

<div id="containernDivs">
	<h1>SHIFT</h1>
    <div class="nDivs_i">
        <form id="nDivsFrm" name="nDivsFrm" action="/nDivs" method="post">
            <div class="input_inform">
                <input type="file" name="file1">
            </div>
        </form>
        <div class="button">
            <div class="nDivs">
                <a href="javascript:getMetaData();" class="">지 역 구 찾 기</a>
            </div>
        </div>
    </div>
</div>


<div id="imgdiv" style="margin-top:10px;"></div>
<div id="text" style="margin-top:5px;font-size:14px"></div>


</body>
</html>