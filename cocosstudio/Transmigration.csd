<GameProjectFile>
  <PropertyGroup Type="Layer" Name="Transmigration" ID="98a0ff29-ae0d-486b-8ff7-4ce11bfd94a5" Version="2.3.1.2" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Layer" CustomClassName="Transmigration" Tag="100" ctype="GameLayerObjectData">
        <Size X="1136.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="menu" ActionTag="-234010910" Tag="101" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="247.7861" RightMargin="279.2139" TopMargin="11.1196" BottomMargin="27.8804" ctype="SpriteObjectData">
            <Size X="609.0000" Y="601.0000" />
            <Children>
              <AbstractNodeData Name="title" ActionTag="-1684386788" Tag="102" IconVisible="False" LeftMargin="157.8981" RightMargin="124.1019" TopMargin="41.3240" BottomMargin="478.6760" LabelText="CONFIRM" ctype="TextBMFontObjectData">
                <Size X="327.0000" Y="81.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="321.3981" Y="519.1760" />
                <Scale ScaleX="0.6000" ScaleY="0.6000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5277" Y="0.8639" />
                <PreSize X="0.0000" Y="0.0000" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="noticeMessage" ActionTag="-574041992" Tag="103" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="131.3984" RightMargin="126.6016" TopMargin="163.0664" BottomMargin="385.9336" FontSize="26" LabelText="ゲームをリセットして、&#xA;ダイアモンドをゲットします" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="351.0000" Y="52.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="131.3984" Y="411.9336" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="60" G="30" B="10" />
                <PrePosition X="0.2158" Y="0.6854" />
                <PreSize X="0.5764" Y="0.0865" />
                <FontResource Type="Normal" Path="font/yasashisa.ttf" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="yesButton" ActionTag="613288947" Tag="104" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="116.3981" RightMargin="292.6019" TopMargin="503.8235" BottomMargin="-22.8234" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="275" Scale9Height="112" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="200.0000" Y="120.0000" />
                <Children>
                  <AbstractNodeData Name="label" ActionTag="-1085773291" Tag="105" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="35.5000" RightMargin="35.5000" TopMargin="19.5000" BottomMargin="19.5000" LabelText="YES" ctype="TextBMFontObjectData">
                    <Size X="129.0000" Y="81.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="100.0000" Y="60.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="0.5000" />
                    <PreSize X="0.6450" Y="0.6750" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
                <Position X="316.3981" Y="37.1766" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5195" Y="0.0619" />
                <PreSize X="0.3284" Y="0.1997" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="ui/button02.png" Plist="" />
                <NormalFileData Type="Normal" Path="ui/button02.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="noButton" ActionTag="-1665158386" Tag="106" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="326.3991" RightMargin="82.6010" TopMargin="502.2159" BottomMargin="-21.2159" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="30" RightEage="30" TopEage="30" BottomEage="30" Scale9OriginX="30" Scale9OriginY="30" Scale9Width="245" Scale9Height="74" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="200.0000" Y="120.0000" />
                <Children>
                  <AbstractNodeData Name="label" ActionTag="-1090088621" Tag="107" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="44.4995" RightMargin="43.5005" TopMargin="16.0321" BottomMargin="22.9679" LabelText="NO" ctype="TextBMFontObjectData">
                    <Size X="112.0000" Y="81.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="100.4995" Y="63.4679" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5025" Y="0.5289" />
                    <PreSize X="0.5600" Y="0.6750" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleY="0.5000" />
                <Position X="326.3991" Y="38.7841" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5360" Y="0.0645" />
                <PreSize X="0.3284" Y="0.1997" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="ui/button02.png" Plist="" />
                <NormalFileData Type="Normal" Path="ui/button02.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="diamond" ActionTag="897822211" Tag="108" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="165.6081" RightMargin="271.3919" TopMargin="391.3994" BottomMargin="61.6006" ctype="SpriteObjectData">
                <Size X="172.0000" Y="148.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="251.6081" Y="135.6006" />
                <Scale ScaleX="0.4000" ScaleY="0.4000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.4131" Y="0.2256" />
                <PreSize X="0.2824" Y="0.2463" />
                <FileData Type="Normal" Path="ui/diamond.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="getDiamondNum" ActionTag="1330995850" Tag="109" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="299.3019" RightMargin="177.6981" TopMargin="424.8989" BottomMargin="95.1011" LabelText="x 10" ctype="TextBMFontObjectData">
                <Size X="132.0000" Y="81.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="365.3019" Y="135.6011" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5998" Y="0.2256" />
                <PreSize X="0.2167" Y="0.1348" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="takeOverFactor" ActionTag="-396843419" Tag="111" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="143.6205" RightMargin="225.3795" TopMargin="290.0656" BottomMargin="223.9344" FontSize="26" LabelText="・図鑑データ&#xA;・所持ダイア&#xA;・ショップデータ" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="216.0000" Y="78.0000" />
                <AnchorPoint ScaleY="1.0000" />
                <Position X="143.6205" Y="310.9344" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="60" G="30" B="10" />
                <PrePosition X="0.2358" Y="0.5174" />
                <PreSize X="0.3941" Y="0.1448" />
                <FontResource Type="Normal" Path="font/yasashisa.ttf" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="takeOver" ActionTag="1441945631" Tag="112" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="120.5722" RightMargin="27.4278" TopMargin="225.7288" BottomMargin="290.2712" LabelText="引き継ぐデータ" ctype="TextBMFontObjectData">
                <Size X="461.0000" Y="85.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="120.5722" Y="332.7712" />
                <Scale ScaleX="0.5000" ScaleY="0.5000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.1980" Y="0.5537" />
                <PreSize X="0.7570" Y="0.1414" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font3.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="getDiamond" ActionTag="-342096562" Tag="113" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="120.5721" RightMargin="-23.5721" TopMargin="364.0765" BottomMargin="151.9235" LabelText="取得できるダイア" ctype="TextBMFontObjectData">
                <Size X="512.0000" Y="85.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="120.5721" Y="194.4235" />
                <Scale ScaleX="0.5000" ScaleY="0.5000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.1980" Y="0.3235" />
                <PreSize X="0.8407" Y="0.1414" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font3.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="552.2861" Y="328.3804" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.4862" Y="0.5131" />
            <PreSize X="0.5361" Y="0.9391" />
            <FileData Type="Normal" Path="ui/menu2.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>