<GameProjectFile>
  <PropertyGroup Type="Node" Name="Shop" ID="c6bcdc23-3df2-4ce8-b7ed-40461e54e6b7" Version="2.3.1.2" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Node" CustomClassName="Shop" Tag="23" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="menu3_8" ActionTag="1163356157" Tag="112" IconVisible="False" LeftMargin="-411.9992" RightMargin="-388.0008" TopMargin="-298.9270" BottomMargin="-302.0730" ctype="SpriteObjectData">
            <Size X="800.0000" Y="601.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="-11.9992" Y="-1.5730" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="ui/menu5.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="title" ActionTag="863392089" Tag="2" IconVisible="False" LeftMargin="-163.5001" RightMargin="-163.4999" TopMargin="-255.5002" BottomMargin="174.5002" LabelText="SHOP" ctype="TextBMFontObjectData">
            <Size X="186.0000" Y="81.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="-0.0001" Y="215.0002" />
            <Scale ScaleX="0.6000" ScaleY="0.7000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="offenseUp" ActionTag="-1966750833" Tag="73" IconVisible="True" LeftMargin="-243.5000" RightMargin="243.5000" TopMargin="-126.8700" BottomMargin="126.8700" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="button" ActionTag="-769078270" Tag="72" IconVisible="False" LeftMargin="291.5000" RightMargin="-589.5000" TopMargin="-50.0000" BottomMargin="-50.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="268" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="298.0000" Y="100.0000" />
                <Children>
                  <AbstractNodeData Name="diamond" ActionTag="511479019" Tag="34" IconVisible="False" LeftMargin="45.3274" RightMargin="180.6726" TopMargin="18.9000" BottomMargin="19.1000" ctype="SpriteObjectData">
                    <Size X="72.0000" Y="62.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="81.3274" Y="50.1000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.2729" Y="0.5010" />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="ui/diamond.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="requreNum" ActionTag="1190380560" Tag="35" IconVisible="False" LeftMargin="129.6968" RightMargin="36.3032" TopMargin="1.8750" BottomMargin="17.1250" LabelText="x 10" ctype="TextBMFontObjectData">
                    <Size X="132.0000" Y="81.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="195.6968" Y="57.6250" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.6567" Y="0.5762" />
                    <PreSize X="0.4430" Y="0.8100" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="nextValue" ActionTag="-11873824" Tag="74" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="-172.0000" RightMargin="298.0000" TopMargin="9.5000" BottomMargin="9.5000" LabelText="1.5倍" ctype="TextBMFontObjectData">
                    <Size X="172.0000" Y="81.0000" />
                    <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
                    <Position Y="50.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition Y="0.5000" />
                    <PreSize X="0.5772" Y="0.8100" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="440.5000" />
                <Scale ScaleX="0.5000" ScaleY="0.5000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="ui/button03.png" Plist="" />
                <NormalFileData Type="Normal" Path="ui/button03.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="description" ActionTag="1237134448" Tag="75" IconVisible="False" LeftMargin="0.0001" RightMargin="-584.0001" TopMargin="-42.5000" BottomMargin="-42.5000" LabelText="動物の攻撃力アップ" ctype="TextBMFontObjectData">
                <Size X="584.0000" Y="85.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="0.0001" />
                <Scale ScaleX="0.4000" ScaleY="0.4000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font3.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="-243.5000" Y="126.8700" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="spawnNum" ActionTag="414492956" Tag="76" IconVisible="True" LeftMargin="-243.5000" RightMargin="243.5000" TopMargin="-57.1200" BottomMargin="57.1200" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="button" ActionTag="1174093055" Tag="77" IconVisible="False" LeftMargin="291.5000" RightMargin="-589.5000" TopMargin="-50.0000" BottomMargin="-50.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="268" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="298.0000" Y="100.0000" />
                <Children>
                  <AbstractNodeData Name="diamond" ActionTag="-1145125184" Tag="78" IconVisible="False" LeftMargin="45.3274" RightMargin="155.6726" TopMargin="18.9000" BottomMargin="19.1000" ctype="SpriteObjectData">
                    <Size X="72.0000" Y="62.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="81.3274" Y="50.1000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.2979" Y="0.5010" />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="ui/diamond.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="requreNum" ActionTag="862108860" Tag="79" IconVisible="False" LeftMargin="129.6968" RightMargin="36.3032" TopMargin="1.8750" BottomMargin="17.1250" LabelText="x 10" ctype="TextBMFontObjectData">
                    <Size X="132.0000" Y="81.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="195.6968" Y="57.6250" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.6567" Y="0.5762" />
                    <PreSize X="0.4430" Y="0.8100" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="nextValue" ActionTag="-151884639" Tag="81" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="-106.0000" RightMargin="298.0000" TopMargin="9.5000" BottomMargin="9.5000" LabelText="2匹" ctype="TextBMFontObjectData">
                    <Size X="106.0000" Y="81.0000" />
                    <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
                    <Position Y="50.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition Y="0.5000" />
                    <PreSize X="0.3557" Y="0.8100" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="440.5000" />
                <Scale ScaleX="0.5000" ScaleY="0.5000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="ui/button03.png" Plist="" />
                <NormalFileData Type="Normal" Path="ui/button03.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="description" ActionTag="1130489786" Tag="80" IconVisible="False" LeftMargin="0.0001" RightMargin="-784.0001" TopMargin="-42.5000" BottomMargin="-42.5000" LabelText="ツボから出てくる動物の数" ctype="TextBMFontObjectData">
                <Size X="784.0000" Y="85.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="0.0001" />
                <Scale ScaleX="0.3700" ScaleY="0.3700" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font3.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="-243.5000" Y="57.1200" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="animalNum" ActionTag="311858175" Tag="82" IconVisible="True" LeftMargin="-243.5000" RightMargin="243.5000" TopMargin="12.6300" BottomMargin="-12.6300" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="button" ActionTag="1617464882" Tag="83" IconVisible="False" LeftMargin="291.5000" RightMargin="-589.5000" TopMargin="-50.0000" BottomMargin="-50.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="268" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="298.0000" Y="100.0000" />
                <Children>
                  <AbstractNodeData Name="diamond" ActionTag="735131389" Tag="84" IconVisible="False" LeftMargin="45.3274" RightMargin="180.6726" TopMargin="18.9000" BottomMargin="19.1000" ctype="SpriteObjectData">
                    <Size X="72.0000" Y="62.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="81.3274" Y="50.1000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.2729" Y="0.5010" />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="ui/diamond.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="requreNum" ActionTag="944320683" Tag="85" IconVisible="False" LeftMargin="129.6968" RightMargin="36.3032" TopMargin="1.8750" BottomMargin="17.1250" LabelText="x 10" ctype="TextBMFontObjectData">
                    <Size X="132.0000" Y="81.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="195.6968" Y="57.6250" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.6567" Y="0.5762" />
                    <PreSize X="0.4430" Y="0.8100" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="nextValue" ActionTag="-200056036" Tag="87" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="-138.0000" RightMargin="298.0000" TopMargin="9.5000" BottomMargin="9.5000" LabelText="21匹" ctype="TextBMFontObjectData">
                    <Size X="138.0000" Y="81.0000" />
                    <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
                    <Position Y="50.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition Y="0.5000" />
                    <PreSize X="0.4631" Y="0.8100" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="440.5000" />
                <Scale ScaleX="0.5000" ScaleY="0.5000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="ui/button03.png" Plist="" />
                <NormalFileData Type="Normal" Path="ui/button03.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="description" ActionTag="436459926" Tag="86" IconVisible="False" LeftMargin="0.0001" RightMargin="-784.0001" TopMargin="-42.5000" BottomMargin="-42.5000" LabelText="保持できる動物の数" ctype="TextBMFontObjectData">
                <Size X="592.0000" Y="85.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="0.0001" />
                <Scale ScaleX="0.4000" ScaleY="0.4000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font3.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="-243.5000" Y="-12.6300" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="getCoin" ActionTag="-1242843452" Tag="88" IconVisible="True" LeftMargin="-243.5000" RightMargin="243.5000" TopMargin="82.3800" BottomMargin="-82.3800" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="button" ActionTag="-547255266" Tag="89" IconVisible="False" LeftMargin="291.5000" RightMargin="-589.5000" TopMargin="-50.0000" BottomMargin="-50.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="268" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="298.0000" Y="100.0000" />
                <Children>
                  <AbstractNodeData Name="diamond" ActionTag="-1572945584" Tag="90" IconVisible="False" LeftMargin="45.3274" RightMargin="180.6726" TopMargin="18.9000" BottomMargin="19.1000" ctype="SpriteObjectData">
                    <Size X="72.0000" Y="62.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="81.3274" Y="50.1000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.2729" Y="0.5010" />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="ui/diamond.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="requreNum" ActionTag="472626450" Tag="91" IconVisible="False" LeftMargin="129.6968" RightMargin="36.3032" TopMargin="1.8750" BottomMargin="17.1250" LabelText="x 10" ctype="TextBMFontObjectData">
                    <Size X="132.0000" Y="81.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="195.6968" Y="57.6250" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.6567" Y="0.5762" />
                    <PreSize X="0.4430" Y="0.8100" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="nextValue" ActionTag="-1476333298" Tag="93" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="-172.0000" RightMargin="298.0000" TopMargin="9.5000" BottomMargin="9.5000" LabelText="1.5倍" ctype="TextBMFontObjectData">
                    <Size X="172.0000" Y="81.0000" />
                    <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
                    <Position Y="50.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition Y="0.5000" />
                    <PreSize X="0.5772" Y="0.8100" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="440.5000" />
                <Scale ScaleX="0.5000" ScaleY="0.5000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="ui/button03.png" Plist="" />
                <NormalFileData Type="Normal" Path="ui/button03.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="description" ActionTag="1090764639" Tag="92" IconVisible="False" LeftMargin="0.0001" RightMargin="-784.0001" TopMargin="-42.5000" BottomMargin="-42.5000" LabelText="コインの取得量" ctype="TextBMFontObjectData">
                <Size X="448.0000" Y="85.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="0.0001" />
                <Scale ScaleX="0.4000" ScaleY="0.4000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font3.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="-243.5000" Y="-82.3800" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="emrgeEnemy" ActionTag="759252109" Tag="94" IconVisible="True" LeftMargin="-243.5000" RightMargin="243.5000" TopMargin="152.1300" BottomMargin="-152.1300" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="button" ActionTag="1927830940" Tag="95" IconVisible="False" LeftMargin="291.5000" RightMargin="-589.5000" TopMargin="-50.0000" BottomMargin="-50.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="268" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="298.0000" Y="100.0000" />
                <Children>
                  <AbstractNodeData Name="diamond" ActionTag="-1437597301" Tag="96" IconVisible="False" LeftMargin="45.3274" RightMargin="180.6726" TopMargin="18.9000" BottomMargin="19.1000" ctype="SpriteObjectData">
                    <Size X="72.0000" Y="62.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="81.3274" Y="50.1000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.2729" Y="0.5010" />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="ui/diamond.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="requreNum" ActionTag="-594480219" Tag="97" IconVisible="False" LeftMargin="129.6968" RightMargin="36.3032" TopMargin="1.8750" BottomMargin="17.1250" LabelText="x 10" ctype="TextBMFontObjectData">
                    <Size X="132.0000" Y="81.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="195.6968" Y="57.6250" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.6567" Y="0.5762" />
                    <PreSize X="0.4430" Y="0.8100" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="nextValue" ActionTag="-1636714382" Tag="99" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="-172.0000" RightMargin="298.0000" TopMargin="9.5000" BottomMargin="9.5000" LabelText="1.5倍" ctype="TextBMFontObjectData">
                    <Size X="172.0000" Y="81.0000" />
                    <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
                    <Position Y="50.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition Y="0.5000" />
                    <PreSize X="0.5772" Y="0.8100" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="440.5000" />
                <Scale ScaleX="0.5000" ScaleY="0.5000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="ui/button03.png" Plist="" />
                <NormalFileData Type="Normal" Path="ui/button03.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="description" ActionTag="1939883957" Tag="98" IconVisible="False" LeftMargin="0.0001" RightMargin="-784.0001" TopMargin="-42.5000" BottomMargin="-42.5000" LabelText="出現する敵の数" ctype="TextBMFontObjectData">
                <Size X="464.0000" Y="85.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="0.0001" />
                <Scale ScaleX="0.4000" ScaleY="0.4000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font3.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="-243.5000" Y="-152.1300" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="okButton" ActionTag="1210879474" Tag="22" IconVisible="False" LeftMargin="-100.0000" RightMargin="-100.0000" TopMargin="207.0000" BottomMargin="-327.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="275" Scale9Height="112" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="200.0000" Y="120.0000" />
            <Children>
              <AbstractNodeData Name="coinLabel_0" ActionTag="-587949728" Tag="23" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="35.5000" RightMargin="35.5000" TopMargin="19.5000" BottomMargin="19.5000" LabelText="OK" ctype="TextBMFontObjectData">
                <Size X="110.0000" Y="81.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="100.0000" Y="60.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5000" />
                <PreSize X="0.6450" Y="0.6750" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position Y="-267.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Normal" Path="ui/button02.png" Plist="" />
            <NormalFileData Type="Normal" Path="ui/button02.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>