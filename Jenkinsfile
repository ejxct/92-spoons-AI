pipeline {
  agent any
  stages {
    stage('GitHub clone') {
      steps {
        git(url: 'https://github.com/ejxct/92-spoons-ai/', branch: 'master')
      }
    }
    stage('Mac Build') {
      steps {
        sh 'mkdir release-mac && clang++ -std=c++11 ai.cpp -o release-mac/ai && zip -r release-mac.zip release-mac'
      }
    }
    stage('GitHub Releases') {
      steps {
        sh 'mkdir release-mac && clang++ -std=c++11 ai.cpp -o release-mac/ai && zip -r release-mac.zip release-mac'
      }
    }
    stage('After-build') {
      steps {
        warnings(canRunOnFailed: true)
        archiveArtifacts '*'
        emailext(subject: '$DEFAULT_SUBJECT', body: '$DEFAULT_CONTENT', attachLog: true, replyTo: '$DEFAULT_REPLYTO', to: '$DEFAULT_RECIPIENTS')
        cleanWs(cleanWhenAborted: true, cleanWhenFailure: true, cleanWhenNotBuilt: true, cleanWhenSuccess: true, cleanWhenUnstable: true, deleteDirs: true, cleanupMatrixParent: true)
      }
    }
  }
}